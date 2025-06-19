#pragma once
using namespace std;

struct Matrix {
    double** elements;
    int size;
    void readMatrixFromFile(ifstream& file, int size);
    Matrix multiplyMatrices(Matrix& B);
    bool isCloseToIdentity(double epsilon);
};
