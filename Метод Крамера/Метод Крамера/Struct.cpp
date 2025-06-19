#include "Struct.h"
#include <fstream>
using namespace std;

equationSystem :: equationSystem(int size)
{
    this->size = size;
    coefficients = new double* [size];
    constants = new double[size];

    for (int i = 0; i < size; i++) 
    {
        coefficients[i] = new double[size];
    }
}

equationSystem :: ~equationSystem() 
{
    cout << endl << "Call destructor\n";
    for (int i = 0; i < size; i++) 
    {
        delete[] coefficients[i];
    }

    delete[] coefficients;
    delete[] constants;
}

void equationSystem :: cramerMethod() 
{
    double detA = calculateDeterminant(coefficients);

    if (detA == 0) 
    {
        std::cout << "Wrong input for Ñramer method.\n";
        return;
    }

    double* solutions = new double[size];

    for (int i = 0; i < size; i++) 
    {
        double** modifiedMatrix = createModifiedMatrix(i);
        solutions[i] = calculateDeterminant(modifiedMatrix) / detA;

        for (int j = 0; j < size; j++) 
        {
            delete[] modifiedMatrix[j];
        }
        delete[] modifiedMatrix;
    }

    std::cout << "Solution is:\n";
    for (int i = 0; i < size; i++) 
    {
        std::cout << "x" << i + 1 << " = " << solutions[i] << std::endl;
    }

    delete[] solutions;
}

double** equationSystem :: createMatrixWithoutRowAndCol(double** matrix, int row, int col, int n)
{
    cout << "call with " << row << " " << col << " " << n << endl;//----------------------------------
    double** temp = new double* [n - 1];
    int tempRow = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == row)
        {
            continue; 
        }

        temp[tempRow] = new double[n - 1];
        int tempCol = 0;

        for (int j = 0; j < n; j++)
        {
            if (j == col)
            {
                continue; 
            }

            cout << "NUM " << i << " " << j << endl;//-------------------------------
            cout << "---" << matrix[i][j] << endl;//-------------------------------

            temp[tempRow][tempCol] = matrix[i][j];
            ++tempCol;
        }

        ++tempRow;
    }

    return temp;
}

double equationSystem :: calculateDeterminant(double** matrix)
{
    if (size == 1) 
    {
        return matrix[0][0];
    }

    double det = 0;
    double** temp = new double* [size - 1];

    for (int i = 0; i < size; ++i) 
    {
        int sign = (i % 2 == 0) ? 1 : -1;
        temp = createMatrixWithoutRowAndCol(matrix, 0, i, size);

        det += sign * matrix[0][i] * calculateDeterminant(temp);

        for (int j = 0; j < size - 1; j++)
        {
            delete[] temp[j];
        }
        delete[] temp;
    }
    return det;
}

double** equationSystem :: createModifiedMatrix(int columnIndex) 
{
    double** modifiedMatrix = new double* [size];

    for (int i = 0; i < size; ++i) 
    {
        modifiedMatrix[i] = new double[size];
        for (int j = 0; j < size; ++j) 
        {
            if (j == columnIndex) 
            {
                modifiedMatrix[i][j] = constants[i];
            }
            else 
            {
                modifiedMatrix[i][j] = coefficients[i][j];
            }
        }
    }

    return modifiedMatrix;
}