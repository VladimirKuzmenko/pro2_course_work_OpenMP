// pro2_course_work_OpenMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "omp.h"
#include <windows.h>
#include <iostream>
#include "operations.h"


using namespace std;

#pragma comment(linker, "/stack:160000000")


const int P = 4;
const int H = N / P;


vector A = new int[N], B, E, Z;
matrix MO, MK, MR, MA;
int alfa;
int minZ = 9999999999;
int main()
{
	cout << "Master started" <<endl;
	omp_lock_t lock_Copy;
	omp_init_lock(&lock_Copy);

	omp_set_num_threads(P);
#pragma omp parallel 
	{
		int id = omp_get_thread_num();
		MA = initMatrix();
		cout << "Task" << id << " started"<<endl;
#pragma omp barrier


		/*================================ Input Data ======================================*/

		switch (id)
		{
			case	0:
				alfa = 1;
				B = inputVector(1);
				MK = inputMatrix(1);
				MR = inputMatrix(1);
			break;
			case	P-1:
				Z = inputVector(1);
				E = inputVector(1);
				MO = inputMatrix(1);
			break;

		}
		/*====================== Sychronized on input =======================================*/
#pragma omp barrier
		int minZid = 9999999999;
		for (int i = id*H; i < (id+1)*H; i++)
		{
			if (Z[i]< minZid)
			{
				minZid = Z[i];
			}
		}

#pragma omp critical
		{
			minZ = min(minZ, minZid);
		}
#pragma omp barrier
		matrix MOid;

		omp_set_lock(&lock_Copy);

		MOid = copyMatrix(MO);

		omp_unset_lock(&lock_Copy);
		

#pragma omp barrier

		int sum;
		for (int i = id * H; i < (id + 1) * H; i++) {
			for (int j = 0; j < N; j++) {
				sum = 0;
				for (int z = 0; z < N; z++) {
					sum += MOid[i][j] * MK[j][z];
				}
				MA[i][j] = sum;
			}
		}

#pragma omp barrier
		vector Bid;
		vector Eid;
		int alfaId;
#pragma omp critical
		{
			alfaId = alfa;
			minZid = minZ;
			Bid = copyVector(B);
			Eid = copyVector(E);
			
		}

		int buf;
		for (int i = id*H; i < (id + 1)*H; i++)
		{
			A[i] = 0;
			for (int j = 0; j < N; j++)
			{
				A[i] += Bid[j] * MA[j][i];
			}
			A[i] = A[i] * alfaId;
			buf = 0;
			for (int j = 0; j < N; j++)
			{
				buf += Eid[j] * MR[j][i];
			}
			A[i] += buf*minZid;
		}

#pragma omp barrier
		if (id==P-1)
		{
			output(A);
		}
#pragma omp barrier
		cout << "Task" << id << " finished" << endl;

		

		

	}

	cout << "Master finished" << endl;
	return 0;
}

