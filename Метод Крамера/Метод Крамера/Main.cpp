#include "Struct.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input number of equations: ";
    cin >> n;

    equationSystem system = equationSystem(n);

    cout << "Input coefficients and constants for each equation:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> system.coefficients[i][j];
        }
        cin >> system.constants[i];
    }

    system.cramerMethod();

    return 0;
}