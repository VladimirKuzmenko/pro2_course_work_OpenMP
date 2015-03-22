

#include "stdafx.h"
#include <windows.h>

using namespace std;

#include "operations.h"
#include <iostream>

vector inputVector(int value){
	vector result = new int[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = value;
	}
	return result;
}

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
void output(vector v) {
	   	if (N <= 10) {
		    for (int i = 0; i < N; i++) {
			 	cout << v[i] << " ";	
			}
		 cout << endl;
		}

}
