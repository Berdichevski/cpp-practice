#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"

using namespace std;

ListEdges listOfEdges(bool** graph, int numVertices)
{
    bool** used = new bool* [numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        used[i] = new bool[numVertices] {0};
    }

    ListEdges list;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] && !used[i][j])
            {
                list.append(to_string(i) + " - " + to_string(j));
                used[j][i] = 1;
            }
        }
    }
    return list;
}

void printList(ListEdges list)
{
    edge* n = list.getHead();
    while (n != nullptr)
    {
        cout << n->data << endl;
        n = n->next;
    }
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
        string line;
        getline(inputFile, line);
        graph[i] = new bool[numVertices];
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

    printList(listOfEdges(graph, numVertices));

    for (int i = 0; i < numVertices; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}