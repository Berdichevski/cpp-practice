#include "Struct.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	
	int iterator = 0;

	ifstream matrixFile("matrix.txt");

	if (!matrixFile.is_open()) 
	{
		cout << "Error input!";
		return 1;
	}

	int amount;
	matrixFile >> amount;
	matrix* allocatedForInputMemory = new matrix[amount];
	bool* flagMatrix = new bool[amount];

	int n; int m;

	for (int _ = 0; _ < amount; _++)
	{
		matrixFile >> n >> m;
		flagMatrix[_] = false;
		allocatedForInputMemory[_] = *new matrix(n, m);
		allocatedForInputMemory[_].readMatrix(matrixFile);
		if (allocatedForInputMemory[_].isSymetrical())
		{
			iterator++;
			flagMatrix[_] = true;
		}
	}

	


	matrixFile.close();

	int* I = new int[iterator];

	int countaer = 0;
	for (int i = 0; i < amount; i++)
	{
		if (flagMatrix[i]) {
			I[countaer] = i;
			countaer++;
		}
	}
	for (int i = 0; i < iterator; i++)
	{
		for (int k = 0; k < iterator - i - 2; k++)
		{
			if (allocatedForInputMemory[I[k]].trace() > allocatedForInputMemory[I[k + 1]].trace())
			{
				int e = I[k];
				I[k] = I[k + 1];
				I[k + 1] = e;
			}
		}
	}

	ofstream outputFile("output210224.txt");

	if (!outputFile.is_open())
	{
		cout << "Error output!";
		return 1;
	}

	for (int i = 0; i < iterator; i++)
	{
		allocatedForInputMemory[I[i]].writeMatrix(outputFile);
		
	}

	outputFile.close();
	delete[] flagMatrix;
	delete[] allocatedForInputMemory;
}


