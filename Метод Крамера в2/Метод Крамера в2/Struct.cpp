#include <iostream>
#include "Struct.h"
using namespace std;

bool LinearSystem::solveSystemKramer()
{
    double detA = 1.0; 
    double** matrixA = coefficients;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) continue;

            detA *= matrixA[i][i] - matrixA[j][i];
        }
    }

    if (detA == 0) {
        cout << "Impossible to use Cramer's method.\n";
        return 0;
    }

    solution = new double[size];

    for (int i = 0; i < size; ++i) {
        double** tempMatrix = new double* [size];
        for (int j = 0; j < size; ++j) {
            tempMatrix[j] = new double[size];
            for (int k = 0; k < size; ++k) {
                tempMatrix[j][k] = k == i ? constants[j] : matrixA[j][k];
            }
        }

        double detAi = 1.0;
        for (int j = 0; j < size; ++j) {
            detAi *= tempMatrix[j][j];
            for (int k = j + 1; k < size; ++k) {
                tempMatrix[j][k] -= tempMatrix[j][j] / tempMatrix[j][j] * tempMatrix[j][k];
            }
        }

        solution[i] = detAi / detA;

        for (int j = 0; j < size; ++j) {
            delete[] tempMatrix[j];
        }
        delete[] tempMatrix;
    }
    return 1;
}
