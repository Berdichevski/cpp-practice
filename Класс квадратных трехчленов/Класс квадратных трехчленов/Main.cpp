#include "Class.h"
#include <iostream>
using namespace std;

int main()
{
	//input trinominal 1
	double* odds1 = new double[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> odds1[i];
	}
	Trinominal trin1 = Trinominal(odds1);

	//input trinominal 2
	double* odds2 = new double[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> odds2[i];
	}
	Trinominal trin2 = Trinominal(odds2);

	//roots of trinominals
	trin1.roots();
	if (trin1.rootsAmount == 1)
	{
		cout << "First trinominal x1 = " << trin1.rootsArr[0] << endl;
	}
	else if (trin1.rootsAmount == 2)
	{
		cout << "First trinominal x1 = " << trin1.rootsArr[0] << "First trinominal x2 = " << trin1.rootsArr[1] << endl;
	}

	trin2.roots();
	if (trin2.rootsAmount == 1)
	{
		cout << "Second trinominal x1 = " << trin2.rootsArr[0] << endl;
	}
	else if (trin2.rootsAmount == 2)
	{
		cout << "Second trinominal x1 = " << trin2.rootsArr[0] << "Second trinominal x2 = " << trin2.rootsArr[1] << endl;
	}

	//sum and its odds output
	Trinominal sumTrin = trin1 + trin2;
	double* oddsSum = sumTrin.getOdds();

	cout << "Odds of sum: ";

	for (int i = 0; i < 3; i++)
	{
		cout << oddsSum[i] << " ";
	}

	cout << endl;

	//roots of sum
	sumTrin.roots();
	if (sumTrin.rootsAmount == 1)
	{
		cout << "Sum of trinominals x1 = " << sumTrin.rootsArr[0] << endl;
	}
	else if (sumTrin.rootsAmount == 2)
	{
		cout << "Sum of trinominals x1 = " << sumTrin.rootsArr[0] << "Sum of trinominals x2 = " << sumTrin.rootsArr[1] << endl;
	}
}