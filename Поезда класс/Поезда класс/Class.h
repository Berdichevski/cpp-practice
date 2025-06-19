#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Train {
    int trainNumber;
    string destination;
    string departureTime;
public:
    bool compareTrains(const Train& t2);
    int getTrainNumber();
    string getDestination();
    string getDepartureTime();
    Train();
    Train(int number, string dest, string time);
};