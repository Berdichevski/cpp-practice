#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CarOwner {
    int carNumber;
    string surname;
    string carName;
public:
    bool compareOwners(const CarOwner& t2);
    int getCarNumber();
    string getSurname();
    string getCarName();
    CarOwner();
    CarOwner(int number, string dest, string time);
};