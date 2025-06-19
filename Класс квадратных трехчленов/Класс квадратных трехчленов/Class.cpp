#include "Class.h"
#include <cmath>
#include <iostream>

using namespace std;

double* Trinominal::getOdds()
{
	return odds;
}

Trinominal Trinominal::operator+(const Trinominal& trin2)
{
	double* oddsSum = new double[3] {0};

	for (int i = 0; i < 3; i++)
	{
		oddsSum[i] += trin2.odds[i];
	}
	for (int i = 0; i < 3; i++)
	{
		oddsSum[i] += odds[i];
	}

	Trinominal trinSum(oddsSum);

	return trinSum;
}

void Trinominal::roots()
{
	double* rootsArr = new double[2];
	//cout << endl << odds[0] << " " << odds[1] << " " << odds[2] << endl;
	double discriminant = (odds[1] * odds[1]) - (4 * odds[0] * odds[2]);
	//cout << endl << discriminant << endl;
	if (discriminant == 0)
	{
		if (odds[0] != 0)
		{
			rootsArr[0] = ((-1) * odds[1] / (2 * odds[0]));
			this->rootsArr = rootsArr;
			this->rootsAmount = 1;
		}
		else
		{
			cout << "Wrong input!" << endl;
		}
	}
	else if (discriminant > 0)
	{
		if (odds[0] != 0)
		{
			rootsArr[0] = ((-1) * odds[1] + sqrt(discriminant) / (2 * odds[0]));
			rootsArr[1] = ((-1) * odds[1] - sqrt(discriminant) / (2 * odds[0]));
			this->rootsArr = rootsArr;
			this->rootsAmount = 2;
		}
		else
		{
			cout << "Wrong input!" << endl;
		}
	}
	else
	{
		cout << "No roots!" << endl;
		this->rootsArr = rootsArr;
		this->rootsAmount = 0;
	}
}

Trinominal::Trinominal(double* odds)
{
	this->odds = odds;
}

