#include <iostream>
#include <string>
using namespace std;

int** CreateMatrix(int a, int b)
{
	int** matrix = new int* [a];
	for (int i = 0; i < a; i++) {
		matrix[i] = new int[b];
		for (int j = 0; j < b; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void PrintMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void DeleteMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool MultiplyMatrix(int** Matrix_1, int** Matrix_2, int r1, int c1, int r2, int c2, int*& result)
{
	if (c1 != r2) return false; //nullptr;
	for (int i = 0; i < r1; i++){
		for (int j = 0; i < c1; j++){
			for (int k = 0; k < c2; k++){
				result[i][j] += Matrix_1[i][k] * Matrix_2[k][j];
			}
		}
	}
	return true;
}

void main()
{
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	auto Matrix_1 = CreateMatrix(n, m);
	auto Matrix_2 = CreateMatrix(k, l);
	auto result = CreateMatrix(n, l);
	if (MultiplyMatrix(Matrix_1, Matrix_2, n, m, k, l, *result))
	{
		cout << "Errorrrr...";
	}
	else
	{
		PrintMatrix(result, n, l);
	}
	DeleteMatrix (result,l);
}