#include "Struct.h"
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int* polynomial::inputf(string polynomial)
{
	int maxDeg = 1;
	string tempDeg = "0";
	for (int i = 0; i < polynomial.length(); i++)
	{
		if (polynomial[i] == '^')
		{
			tempDeg = "";
			int j = 1;
			while (isdigit(polynomial[i + j]))
			{
				tempDeg += polynomial[i + j];
				j++;
				//cout << tempDeg << endl;
			}
		}

		if (stoi(tempDeg) > maxDeg)
		{
			maxDeg = stoi(tempDeg);
		}
	}

	int* odds = new int[maxDeg + 1]();
	//cout << maxDeg + 1;

	string tempOdd = "";
	bool sign = 0;
	bool flagDeg = 0;
	tempDeg = "";
	for (int i = 0; i < polynomial.length(); i++)
	{
		if (polynomial[i] == '-')
		{
			if (tempOdd == "")
			{
				tempOdd = "1";
			}
			if (tempDeg != "")
			{
				odds[stoi(tempDeg)] = pow(-1, sign) * stoi(tempOdd);
			}
			flagDeg = 0;
			tempDeg = "0";
			tempOdd = "";
			sign = 1;
		}
		else if (polynomial[i] == '+')
		{
			//cout << endl << tempDeg << " " << tempOdd << endl;
			if (tempOdd == "")
			{
				tempOdd = "1";
			}
			if (tempDeg != "")
			{
				odds[stoi(tempDeg)] = pow(-1, sign) * stoi(tempOdd);
			}
			flagDeg = 0;
			tempDeg = "0";
			tempOdd = "";
			sign = 0;
		}
		else if (polynomial[i] == '^')
		{
			tempDeg = "";
			flagDeg = 1;
		}
		else if ((isdigit(polynomial[i]) || (polynomial[i] == '.')) && flagDeg == 0)
		{
			tempOdd += polynomial[i];
		}
		else if (isdigit(polynomial[i]) && flagDeg == 1)
		{
			tempDeg += polynomial[i];
		}
		if (polynomial[i] == 'x')
		{
			tempDeg = "1";
		}
	}

	if (flagDeg == 0 && isdigit(polynomial[polynomial.length() - 1]))
	{
		odds[0] = pow(-1, sign) * stoi(tempOdd);
	}

	this->degree = maxDeg + 1;

	/*cout << "vivod odds" << endl;
	for (int i = 0; i < degree; i++)
	{
		cout << odds[i] << " ";
	}
	cout << endl << "konets vivod odds" << endl;*/

	this->odds = odds;

	return nullptr;
}

string polynomial::outputf(int* odds, int deg)
{
	string resultString = "";
	if (odds[0] != 0)
	{
		if (odds[0] < 0)
		{
			resultString = "(" + to_string(odds[0]) + ")";
		}
		else
		{
			resultString = to_string(odds[0]);
		}
	}
	if (deg > 1)
	{
		if (odds[1] != 0)
		{
			if (odds[1] < 0)
			{
				resultString = "(" + to_string(odds[1]) + ")x" + "+" + resultString;
			}
			else
			{
				resultString = to_string(odds[1]) + "x" + "+" + resultString;
			}
		}
		for (int i = 2; i < deg; i++)
		{
			if (odds[i] != 0)
			{
				if (odds[i] < 0)
				{
					resultString = "(" + to_string(odds[i]) + ")x^" + to_string(i) + "+" + resultString;
				}
				else
				{
					resultString = to_string(odds[i]) + "x^" + to_string(i) + "+" + resultString;
				}
			}
		}
	}
	return resultString;
}

int* polynomial::derivativeOdds(int* odds)
{
	int* oddsDer = new int[degree - 1];
	//cout << degree << endl;
	for (int i = 1; i < degree; i++)
	{
		oddsDer[i - 1] = odds[i] * i;
	}
	this->oddsDer = oddsDer;

	return 0;
}

int polynomial::valInPoint(int* odds, int point, int deg)
{
	double value = 0;
	for (int i = 0; i < deg; i++)
	{
		value += pow(point, i) * odds[i];
		/*		cout << "umoshili " << pow(point, i) << " na " << odds[i] << " poluchili "
					<< pow(point, i) * odds[i] << " sloshili i poluchili " << value << ", ";
			cout << endl;*/
	}
	return value;
}

int* polynomial::sum(polynomial poly2)
{
	int* oddsSum = new int[max(degree, poly2.degree)] {0};

	for (int i = 0; i < poly2.degree; i++)
	{
		oddsSum[i] += poly2.odds[i];
	}
	for (int i = 0; i < degree; i++)
	{
		oddsSum[i] += odds[i];
	}
	
	return oddsSum;
}

int* polynomial::residual(polynomial poly2)
{
	int* oddsResidual = new int[max(degree, poly2.degree)] {0};

	for (int i = 0; i < degree; i++)
	{
		oddsResidual[i] = odds[i];
	}
	for (int i = 0; i < poly2.degree; i++)
	{
		oddsResidual[i] -= poly2.odds[i];
	}

	return oddsResidual;
}

int* polynomial::multipl(polynomial poly2)
{
	int* oddsMultipl = new int[degree + poly2.degree - 1];
	for (int i = 0; i <= degree + poly2.degree - 1; i++)
	{
		oddsMultipl[i] = 0;
	}

	for (int i = 0; i <= degree - 1; i++)
	{
		for (int j = 0; j <= poly2.degree - 1; j++)
		{
			oddsMultipl[i + j] += odds[i] * poly2.odds[j];
		}
	}

	return oddsMultipl;
}

int* polynomial::divis(polynomial poly2)
{
	int* oddsDivis = new int[degree - poly2.degree + 1];

	int* tempOdds = new int[degree];
	for (int i = 0; i < degree; i++) {
		tempOdds[i] = odds[i];
	}

	for (int i = 0; i <= degree - poly2.degree; i++) {
		oddsDivis[i] = tempOdds[i] / poly2.odds[0]; // Calculate the current quotient

		for (int j = 0; j < poly2.degree; j++) {
			tempOdds[i + j] -= oddsDivis[i] * poly2.odds[j]; // Update the dividend correctly
		}
	}

	delete[] tempOdds;

	/*cout << "vivod odds" << endl;
	for (int i = 0; i < degree - poly2.degree + 1; i++)
	{
		cout << oddsDivis[i] << " ";
	}
	cout << endl << "konets vivod odds" << endl;*/

	return oddsDivis;
}

