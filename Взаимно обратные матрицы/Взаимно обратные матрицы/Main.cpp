#include "Struct.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    //считываем матрицу
    ifstream matrixFile("matrix.txt");

    if (!matrixFile.is_open())
    {
        cout << "Error input!";
        return 1;
    }
    
    int k;
    matrixFile >> k;
    matrix* structsArr = new matrix[k];
    int n;
    int nMax = 0;
    for (int i = 0; i < k; i++)
    {
        matrixFile >> n;
        if (structsArr[i].n > nMax)
        {
            nMax = structsArr[i].n;
        }
    
        double** matrIn = new double* [n];
        for (int j = 0; j < n; j++)
        {
            matrIn[j] = new double[n];
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                matrixFile >> matrIn[j][k];
            }
        }

        structsArr[i] = matrix(n,matrIn);
        /*
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << structsArr[i].data[i][j] << " ";
            }
            cout << endl;
        }
        */

    }


    //создаем эталонную единичнцю матрицу нужного размера
    double** etalonMatrix = new double* [nMax];
    for (int i = 0; i < nMax; i++)
    {
        etalonMatrix[i] = new double[nMax];
    }
    for (int i = 0; i < nMax; i++)
    {
        for (int j = 0; j < nMax; j++)
        {
            if (i == j)
            {
                etalonMatrix[i][j] = 1;
            }
            else
            {
                etalonMatrix[i][j] = 0;
            }
        }
    }

    double epsilon = DBL_EPSILON;

    //произведение матриц и проверка произведения на стремление к эталонной, вывод 
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double** resMult = structsArr[i].multiply(structsArr[j]);
            //----------------------------------------------
            for (int k = 0; k < n; ++k)
            {
                for (int r = 0; r < n; ++r)
                {
                    cout << etalonMatrix[k][r] << " ";
                }
                cout << endl;
            }
            //----------------------------------------------
            if (structsArr[i].isComparable(resMult, etalonMatrix,epsilon))
            {
                structsArr[i].writeMatrix();
                cout << " and " << endl;
                structsArr[j].writeMatrix();
                cout << "---------------------" << endl;
            }
        }
    }
}
