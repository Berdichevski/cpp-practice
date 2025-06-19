#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cout << "Error opening input file." << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile)
    {
        cout << "Error opening output file." << endl;
        return 1;
    }

    int polygonesAmount;
    inputFile >> polygonesAmount;

    Polygon* polygons = new Polygon[polygonesAmount];

    int verticesAmount;
    double x, y;

    for (int i = 0; i < polygonesAmount; i++)
    {
        inputFile >> verticesAmount;
        point* vertices = new point[verticesAmount];

        for (int j = 0; j < verticesAmount; j++)
        {
            inputFile >> x >> y;
            point vertix = point(x, y);
            vertices[j].copy(vertix);
        }

        polygons[i] = Polygon(verticesAmount, vertices);
    }

    int* I = new int[polygonesAmount];

    for (int i = 0; i < polygonesAmount; i++)
    {
        I[i] = i;
    }

    int min_idx;
    for (int i = 0; i < polygonesAmount - 1; i++)
    {
        min_idx = i;
        for (int k = i + 1; k < polygonesAmount; k++)
        {
            if (polygons[I[min_idx]].diagonalLength() < polygons[I[k]].diagonalLength())
            {
                min_idx = k;
            }
        }
        int e = I[i];
        I[i] = I[min_idx];
        I[min_idx] = e;
    }

    for (int i = 0; i < polygonesAmount; i++)
    {
        if (polygons[I[i]].isConvex())
        {
            verticesAmount = polygons[I[i]].getVerticesAmount();
            outputFile << verticesAmount << endl;
            for (int j = 0; j < verticesAmount; j++)
            {
                outputFile << polygons[I[i]].getVertices()[j].x << " " << polygons[I[i]].getVertices()[j].y << endl;
            }
            outputFile << "Perimeter = " << polygons[I[i]].perimeter() << endl;
            outputFile << "Area = " << polygons[I[i]].area() << endl;
            outputFile << "Max diagonal = " << polygons[I[i]].diagonalLength() << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    for (int i = 0; i < polygonesAmount; i++)
    {
        delete[] polygons[i].getVertices();
    }

    delete[] polygons;

    delete[] I;

}

    