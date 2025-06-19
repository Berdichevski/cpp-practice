#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Class.h"
using namespace std;

int main() {
    ifstream inputFile("carOwners.txt");
    if (!inputFile)
    {
        cout << "Error opening input file." << endl;
        return 1;
    }

    int amount;
    inputFile >> amount;

    CarOwner* carOwners = new CarOwner[amount];

    int carNumber;
    string surname, carName;

    for (int i = 0; i < amount; i++)
    {
        inputFile >> carNumber >> surname >> carName;
        carOwners[i] = CarOwner(carNumber, surname, carName);
    }

    inputFile.close();

    int* I = new int[amount];

    for (int i = 0; i < amount; i++)
    {
        I[i] = i;
    }

    int min_idx;
    for (int i = 0; i < amount - 1; i++)
    {
        min_idx = i;
        for (int k = i+1; k < amount; k++)
        {
            if (carOwners[I[min_idx]].compareOwners(carOwners[I[k]]))
            {
                min_idx = k;
            }
        }
        int e = I[i];
        I[i] = I[min_idx];
        I[min_idx] = e;
    }

    ofstream outputFile("sorted_carOwners.txt");
    if (!outputFile) {
        cout << "Error creating output file." << endl;
        delete[] carOwners;
        return 1;
    }

    string wantedName;
    cin >> wantedName;

    bool flagSuc = 0;

    for (int i = 0; i < amount; i++)
    {
        if (carOwners[I[i]].getCarName() == wantedName)
        {
            flagSuc = 1;
            outputFile << carOwners[I[i]].getCarNumber() << " " << carOwners[I[i]].getSurname() << " " << carOwners[I[i]].getCarName() << endl;
        }
    }

    if (flagSuc == 0)
    {
        outputFile << "No cars found!";
    }

    outputFile.close();

    delete[] carOwners;

    return 0;
}
