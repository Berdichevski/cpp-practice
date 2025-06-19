#include <iostream>
#include "Struct.h"

using namespace std;

int main() {
    LinearSystem sys;

    cout << "Input size: ";
    cin >> sys.size;

    sys.coefficients = new double* [sys.size];
    sys.constants = new double[sys.size];

    cout << "Input coefficients and constants: \n";
    for (int i = 0; i < sys.size; ++i) {
        sys.coefficients[i] = new double[sys.size];
        for (int j = 0; j < sys.size; ++j) {
            cin >> sys.coefficients[i][j];
        }
        cin >> sys.constants[i];
    }

    bool flag;
    flag = sys.solveSystemKramer();

    if (flag)
    {
        cout << "Solution of the system: \n";
        for (int i = 0; i < sys.size; ++i) {
            cout << "x" << i + 1 << " = " << sys.solution[i] << "\n";
        }
    }

    for (int i = 0; i < sys.size; ++i) {
        delete[] sys.coefficients[i];
    }
    delete[] sys.coefficients;
    delete[] sys.constants;
    delete[] sys.solution;

    return 0;
}