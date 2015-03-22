// pro2_course_work_OpenMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "omp.h"
#include <windows.h>
#include <iostream>
#include "operations.h"
#include <ctime>


using namespace std;

#pragma comment(linker, "/stack:160000000")

const int P = 6;
const int H = N / P;

vector A = new int[N], B, E, Z;
matrix MO, MK, MR, MA;
int alfa;
int minZ = 9999999999;
omp_lock_t lock_Copy;

int main()
{
	unsigned int start_time = clock();

	omp_init_lock(&lock_Copy);
	omp_set_num_threads(P);
#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		MA = initMatrix();
		cout << "Task" << tid << " started"<<endl;
		switch (tid)
		{
			/*1. Якщо tid = 0 Ввести α, B, MK, MR.*/
			case	0:
				alfa = 1;
				B = inputVector(1);
				MK = inputMatrix(1);
				MR = inputMatrix(1);
			break;
			/*2. Якщо tid = P-1 ввести Z, E, MO.*/
			case	P-1:
				Z = inputVector(1);
				E = inputVector(1);
				MO = inputMatrix(1);
			break;

		}
		/*3. Бар’єр для усіх задач. Синхронізація по вводу*/
#pragma omp barrier
		/*4. Обчислення minZi = min(Z), i = (0,P-1) */
		int minZid = 9999999999;
		for (int i = tid*H; i < (tid+1)*H; i++)
		{
			if (Z[i]< minZid)
			{
				minZid = Z[i];
			}
		}
		/*5. Обчислення minZ = min(minZ, minZi), i = (0,P-1) ̅.*/
#pragma omp critical
		{
			minZ = min(minZ, minZid);
		}
		/*6. Бар’єр для усіх задач. Синхронізація по обрахунку minZ*/
#pragma omp barrier
		matrix MOid;
		/*7. Копіювати MOi=MO*/
		omp_set_lock(&lock_Copy);

		MOid = copyMatrix(MO);

		omp_unset_lock(&lock_Copy);
		
		int sum;
		for (int i = tid * H; i < (tid + 1) * H; i++) {
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
		for (int i = tid*H; i < (tid + 1)*H; i++)
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
		if (tid==P-1)
		{
			output(A);
		}

		cout << "Task" << tid << " finished" << endl;
	}
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	cout << "Time working" << search_time << endl;
	return 0;
}

