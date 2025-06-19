#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int n;
    cin >> n;

    int** array = new int* [n];

    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (n % 2 == 0)
                array[i][j] = abs((i + j) % 2 - 1);
            else
                array[i][j] = (i + j) % 2;
        }
    }

    ofstream outputFile("outputFile.txt");
    if (outputFile.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
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
}