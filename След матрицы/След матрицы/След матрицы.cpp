#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream inputFile("inputFile.txt");

    if (!inputFile.is_open()) {
        cout << "Error" << endl;
        return 1;
    }

    int maxPrint = 0;

    while (inputFile)
    {
        int print = 0;
        int m;
        inputFile >> m;

        if (!inputFile) {
            break;
        }

        int** array = new int* [m];

        for (int i = 0; i < m; i++) 
        {
            array[i] = new int[m];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++) 
            {
                inputFile >> array[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    print += array[i][j];
                }
            }
        }

        cout << maxPrint << " " << print << endl;

        if (print > maxPrint)
        {
            ofstream outputFile("outputFile.txt", ofstream::trunc);
            if (outputFile.is_open())
            {
                outputFile << m << endl;
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        outputFile << array[i][j] << " ";
                    }
                    outputFile << endl;
                }
                outputFile.close();
            }
            else 
            {
                cout << "Error";
            }
            maxPrint = print;
        }

        for (int i = 0; i < m; i++) 
        {
            delete[] array[i];
        }

        delete[] array;
    }

    inputFile.close();

    return 0;
}