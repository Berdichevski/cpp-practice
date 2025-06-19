#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() 
{
	List* polynome1 = new List;
	List* polynome2 = new List;
	int amount;
	cout << "Insert amount of terms in the first polyndrome." << endl;
	cin >> amount;
	int degree;
	double coefficient;
	for (int i = 0; i < amount; i++)
	{
		cin >> degree >> coefficient;
		polynome1->Append(degree, coefficient);
	}

	cout << "Insert amount of terms in the second polyndrome." << endl;
	cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		cin >> degree >> coefficient;
		polynome2->Append(degree, coefficient);
	}

	List* polynomesSum = polynome1->sumPolynominals(polynome2);
	List* derivative1 = polynome1->derivative();
	List* derivative2 = polynome2->derivative();


	cout << "Answer: " << endl;
	polynomesSum->printList();
	derivative1->printList();
	derivative2->printList();
}