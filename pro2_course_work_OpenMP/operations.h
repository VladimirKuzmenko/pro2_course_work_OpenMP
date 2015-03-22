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

typedef int* vector;
typedef int** matrix;

const int N = 1200;

vector inputVector(int);
matrix inputMatrix(int);
void output(vector);
void output(matrix);
vector copyVector(vector);
matrix copyMatrix(matrix);
matrix initMatrix();

