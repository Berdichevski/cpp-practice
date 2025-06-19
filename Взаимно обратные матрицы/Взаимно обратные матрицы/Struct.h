#pragma once
#include <iostream>
using namespace std;

struct matrix {
	int n;
	double** data;
	matrix();
	matrix(int n, double** matrIn);
	~matrix();
	void writeMatrix();
	double** multiply(const matrix& Matr2);
	bool isComparable(double** resMult, double** etalonMatrix, double epsilon);
};