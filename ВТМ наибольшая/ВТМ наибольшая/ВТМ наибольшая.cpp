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

    int maxSize = 0;

    while (inputFile)
    {
        bool flag = 1;
        int print = 0;
        int m;

        if (!inputFile) {
            break;
        }

        inputFile >> m;

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
                if (j < i)
                {
                    if (array[i][j] != 0)
                    {
                        flag = 0;
                    }
                }
            }
        }

        if ((flag == 1) && (m > maxSize))
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
            maxSize = m;
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