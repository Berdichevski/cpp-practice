#include <iostream>
#include "Class.h"
#include <fstream>
#include <string>
using namespace std;

CarOwner::CarOwner(int number, string surname, string carName) : carNumber(number), surname(surname), carName(carName) {}

CarOwner::CarOwner()
    : carNumber(0), surname("Undefined"), carName("Undefined") {}

bool CarOwner::compareOwners(const CarOwner& c2) {
    return carNumber > c2.carNumber;
}

int CarOwner::getCarNumber()
{
    return carNumber;
}

string CarOwner::getSurname()
{
    return surname;
}

string CarOwner::getCarName()
{
    return carName;
}
