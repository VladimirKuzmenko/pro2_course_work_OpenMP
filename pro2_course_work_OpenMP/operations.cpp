/**
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                             *
*            Програмування паралельний комп'ютерних сисем     *
*             Курсова робота. ПРГ1. Бібліотека OpenMP         *
*                                                             *
* Завдання: A = B(MO*MK)*a + min(Z)*E*MR                      *
*                                                             *
* Автор Кузьменко Володимир                                   *
* Група ІО-21                                                 *
* Датаe 23.03.15                                              *
*                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/


#include "stdafx.h"
#include <windows.h>


using namespace std;

#include "operations.h"
#include <iostream>
/*Введення вектора*/
vector inputVector(int value){
	vector result = new int[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = value;
	}
	return result;
}
/*введення матриці*/
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
/*Виведення вектора*/
void output(vector v) {
	   	if (N <= 20) {
		    for (int i = 0; i < N; i++) {
			 	cout << v[i] << " ";	
			}
		 cout << endl;
		}
}
/*Копіювання вектора*/
vector copyVector(vector v){
	vector result = new int[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = v[i];
	}
	return result;
}
/*Копіювання матриці*/
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
/*Ініціалізація матриці*/
matrix initMatrix(){
	matrix result = new vector[N];
	for (int i = 0; i < N; i++)
	{
		result[i] = new int[N];
	}
	return result;
}
