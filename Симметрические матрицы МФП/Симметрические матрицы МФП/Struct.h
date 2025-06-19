#pragma once
#include <iostream>
using namespace std;

struct matrix {
	int n; int m;
	double** data;
	double trace();
	matrix();
	matrix(const int &n, const int &m);
	~matrix();
	void readMatrix(ifstream& fin); 
	bool isSymetrical();
	void writeMatrix(ofstream& fin);
};
