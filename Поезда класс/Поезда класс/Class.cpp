#include <iostream>
#include "Class.h"
#include <fstream>
#include <string>
using namespace std;

Train::Train(int number, string dest, string time) : trainNumber(number), destination(dest), departureTime(time) {}

Train::Train()
    : trainNumber(0), destination("Undefined"), departureTime("00:00") {}

bool Train::compareTrains(const Train& t2) {
    if (destination == t2.destination) {
        return departureTime < t2.departureTime;
    }
    return destination < t2.destination;
}

int Train::getTrainNumber()
{
    return trainNumber;
}

string Train::getDestination()
{
    return destination;
}

string Train::getDepartureTime()
{
    return departureTime;
}
