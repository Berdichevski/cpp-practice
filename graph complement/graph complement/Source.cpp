#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int** buildComplement(int** graph, int numVertices) 
{
    int** complement = new int* [numVertices];
    for (int i = 0; i < numVertices; ++i) 
    {
        complement[i] = new int[numVertices]();
    }

    for (int i = 0; i < numVertices; ++i) 
    {
        for (int j = 0; j < numVertices; ++j) 
        {
            if (!graph[i][j] || (i==j))
            {
                complement[i][j] = 1;
            }

        }
    }

    return complement;
}

bool inLine(string line, int num)
{
    int temp;
    bool flag = 0;
    stringstream ss(line);
    while (ss >> temp)
    {
        if (temp == num)
        {
            flag = 1;
        }
    }
    return flag;
}

void printNeighbours(int** graph, int numVertices) 
{
    for (int i = 0; i < numVertices; ++i) 
    {
        cout << "For " << i << ": ";
        for (int j = 0; j < numVertices; ++j) 
        {
            if (graph[i][j] == 1) 
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

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

    int** graph = new int* [numVertices];
    for (int i = 0; i < numVertices; ++i) 
    {
        string line;
        getline(inputFile, line);
        graph[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) 
        {
            if (inLine(line, j))
            {
                graph[i][j] = 1;
            }
            else
            {
                graph[i][j] = 0;
            }
        }
    }

    inputFile.close(); 

    int** complementGraph = buildComplement(graph, numVertices);

    printNeighbours(complementGraph, numVertices);

    for (int i = 0; i < numVertices; ++i) {
        delete[] graph[i];
        delete[] complementGraph[i];
    }
    delete[] graph;
    delete[] complementGraph;

    return 0;
}