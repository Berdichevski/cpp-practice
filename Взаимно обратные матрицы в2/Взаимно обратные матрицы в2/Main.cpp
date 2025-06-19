#include <iostream>
#include <fstream>
#include <cmath>
#include "Struct.h"

int main() {
    ifstream file("matrix.txt");
    if (!file.is_open()) {
        cout << "Error opening.\n";
        return 1;
    }

    double epsilon = DBL_EPSILON; 

    int numPairs;
    file >> numPairs;

    for (int pair = 1; pair <= numPairs; ++pair) {
        int size;
        file >> size;

        Matrix matrixA; 
        matrixA.readMatrixFromFile(file, size);
        Matrix matrixB; 
        matrixB.readMatrixFromFile(file, size);

        Matrix product = matrixA.multiplyMatrices(matrixB);

        cout << "Pair of matrices " << pair << ":\n";
        if (product.isCloseToIdentity(epsilon)) {
            cout << "Matrices are mutually inversive.\n";
        }
        else {
            cout << "Matrices are not mutually inversive.\n";
        }

        // Освобождение памяти
        for (int i = 0; i < size; ++i) {
            delete[] matrixA.elements[i];
            delete[] matrixB.elements[i];
            delete[] product.elements[i];
        }
        delete[] matrixA.elements;
        delete[] matrixB.elements;
        delete[] product.elements;
    }

    file.close();

    return 0;
}