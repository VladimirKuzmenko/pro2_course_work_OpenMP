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
matrix MO, MK, MR;
int alfa;

int main()
{
	cout << "Master started" <<"\n";
	//omp_lock_t lock_C;
	//omp_init_lock(&lock_C);
	omp_set_num_threads(P);
#pragma omp parallel 
	{
		int id = omp_get_thread_num();

		cout << "T" << id << " started\n";


		/*================================ Input Data ======================================*/

		switch (id)
		{
			case	0:

			break;
			case	P-1:

			break;

		}

	}
	cout << "Master finished" << "\n";
	return 0;
}

