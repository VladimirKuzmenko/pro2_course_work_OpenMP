/**
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                             *
*            ������������� ����������� ����'������� �����     *
*             ������� ������. ���1. ��������� OpenMP         *
*                                                             *
* ��������: A = B(MO*MK)*a + min(Z)*E*MR                      *
*                                                             *
* ����� ��������� ���������                                   *
* ����� ��-21                                                 *
* ����e 23.03.15                                              *
*                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


#include "stdafx.h"
#include <windows.h>


using namespace std;

#include "operations.h"
#include <iostream>
/*�������� �������*/
vector inputVector(int value){
	vector result = new int[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = value;
	}
	return result;
}
/*�������� �������*/
matrix inputMatrix(int value){
	matrix result = new vector[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i][j] = value;
		}
	}
	return result;
}
/*��������� �������*/
void output(vector v) {
	   	if (N <= 20) {
		    for (int i = 0; i < N; i++) {
			 	cout << v[i] << " ";	
			}
		 cout << endl;
		}
}
/*��������� �������*/
vector copyVector(vector v){
	vector result = new int[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = v[i];
	}
	return result;
}
/*��������� �������*/
matrix copyMatrix(matrix m){
	matrix result = new vector[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i][j] = m[i][j];
		}
	}
	return result;
}
/*����������� �������*/
matrix initMatrix(){
	matrix result = new vector[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = new int[N];
	}
	return result;
}
