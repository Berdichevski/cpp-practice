#include <iostream>
#include <fstream>
#include <cctype>
#include "Header.h"
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }

    int numVertices;
    inputFile >> numVertices;
    int m = 0;

    IncidenceMatrix incidenceMatr;
    for (int i = 0; i < numVertices; ++i)
    {
        int n;
        inputFile >> n;
        while (n != 0)
        {
//            cout << i << " " << n << endl;
            if (n > i)
            {
                m++;
                incidenceMatr.append(i, n - 1, numVertices);
            }
            inputFile >> n;
        }
    }

    cout << "n = " << numVertices << "\n\n";
    cout << "m = " << m << "\n\n";

    incidenceMatr.printMatrix(numVertices);

    inputFile.close();
    return 0;
}