#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Class.h"
using namespace std;

int main() {
    ifstream inputFile("trains.txt");
    if (!inputFile) 
    {
        cout << "Error opening input file." << endl;
        return 1;
    }

    int amount;
    inputFile >> amount;

    Train* trains = new Train[amount];
 
    int number;
    string destination, time;

    for (int i = 0; i < amount; i++)
    {
        inputFile >> number >> destination >> time;
        trains[i] = Train(number, destination, time);
    }

    inputFile.close();

    int* I = new int[amount];

    for (int i = 0; i < amount; i++)
    {
        I[i] = i;
    }
    for (int i = 0; i < amount; i++)
    {
        for (int k = 0; k < amount - i - 1; k++)
        {
            if (!(trains[I[k]].compareTrains(trains[I[k+1]])))
            {
                int e = I[k];
                I[k] = I[k + 1];
                I[k + 1] = e;
            }
        }
    }

    ofstream outputFile("sorted_trains.txt");
    if (!outputFile) {
        cout << "Error creating output file." << endl;
        delete[] trains;
        return 1;
    }

    for (int i = 0; i < amount; i++) 
    {
        outputFile << trains[I[i]].getTrainNumber() << " " << trains[I[i]].getDestination() << " " << trains[I[i]].getDepartureTime() << endl;
    }

    outputFile.close();

    delete[] trains;

    return 0;
}
