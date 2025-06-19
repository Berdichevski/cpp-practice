#include "Struct.h"
#include <fstream>
using namespace std;

matrix::matrix()
{
    this->n = 0;
    this->data = nullptr;
}

matrix::matrix(int n, double** matrIn)
{
    this->n = n;

    this->data = new double* [n];
    for (int i = 0; i < n; i++)
    {
        this->data[i] = new double[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            this->data[i][j] = matrIn[i][j];
        }
    }
}


matrix::~matrix()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

void matrix::writeMatrix()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double** matrix::multiply(const matrix& Matr2)
{
    if (n != Matr2.n) {
        cout << "Matrices are not the same size!" << endl;
        return nullptr;
    }

    double** result = new double* [n];
    for (int i = 0; i < n; ++i) 
    {
        result[i] = new double[n]();
    }

    //----------------------------------------------
    for (int k = 0; k < n; ++k)
    {
        for (int r = 0; r < n; ++r)
        {
            cout << data[k][r] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int k = 0; k < n; ++k)
    {
        for (int r = 0; r < n; ++r)
        {
            cout << Matr2.data[k][r] << " ";
        }
        cout << endl;
    }
    //-------------------------------------------------

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            for (int k = 0; k < n; ++k) 
            {
                result[i][j] += data[i][k] * Matr2.data[k][j];
            }
        }
    }

    return result;
}

bool matrix::isComparable(double** resMult, double** etalonMatrix, double epsilon)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (abs(resMult[i][j] - etalonMatrix[i][j]) >= epsilon)
            {
                return false;
            }
        }
    }

    return true;
}
