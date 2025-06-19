#pragma once
#include <iostream>
using namespace std;

struct equationSystem 
{
    double** coefficients; 
    double* constants;      
    int size;              

    equationSystem(int size);
    ~equationSystem();
    void cramerMethod();
    double** createMatrixWithoutRowAndCol(double** matrix, int row, int col, int n);
    double calculateDeterminant(double** matrix);
    double** createModifiedMatrix(int columnIndex);
};

