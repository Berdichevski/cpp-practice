#include <iostream>
#include <fstream>
#include <cmath>
#include "Struct.h"
using namespace std;

void Matrix::readMatrixFromFile(ifstream& file, int size) {

    this->size = size;

    this->elements = new double* [size];
    for (int i = 0; i < size; ++i) 
    {
        this->elements[i] = new double[size];
        for (int j = 0; j < size; ++j) 
        {
            file >> this->elements[i][j];
        }
    }
}

Matrix Matrix::multiplyMatrices(Matrix& B) {
    Matrix result;
    result.size = size;

    result.elements = new double* [result.size];
    for (int i = 0; i < result.size; ++i) 
    {
        result.elements[i] = new double[result.size];
        for (int j = 0; j < result.size; ++j) 
        {
            result.elements[i][j] = 0.0;
            for (int k = 0; k < result.size; ++k) 
            {
                result.elements[i][j] += elements[i][k] * B.elements[k][j];
            }
        }
    }

    return result;
}

bool Matrix::isCloseToIdentity(double epsilon) {
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            if (i == j) {
                if (abs(elements[i][j] - 1.0) >= epsilon) 
                {
                    return false;
                }
            }
            else {
                if (abs(elements[i][j]) >= epsilon) 
                {
                    return false;
                }
            }
        }
    }

    return true;
}