#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

    bool** graph = new bool* [numVertices];

    for (int i = 0; i < numVertices; ++i)
    {
        graph[i] = new bool[numVertices];
    }

    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();

    int k = 0;

    for (int i = 0; i < numVertices; ++i)
    {
        bool flagIsolated = 1;
        for (int j = 0; j < numVertices; ++j)
        {
            if (graph[i][j])
            {
                flagIsolated = 0;
            }
        }
        if (flagIsolated)
        {
            k++;
        }
    }

    cout << k;

    for (int i = 0; i < numVertices; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}