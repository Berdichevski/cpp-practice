#include "Struct.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	polynomial poly;
	string stringInput;
	cin >> stringInput;
	poly.inputf(stringInput);
	cout << "Degree = " << poly.degree - 1 << endl;
	cout << poly.outputf(poly.odds, poly.degree) << endl;
	poly.derivativeOdds(poly.odds);
	for (int i = 0; i < poly.degree - 1; i++)
	{
		cout << poly.oddsDer[i] << " ";
	}
	cout << endl;
	cout << poly.outputf(poly.oddsDer, poly.degree-1) << endl;

	int point;
	cout << "Input your point!" << endl;
	cin >> point;
	cout << poly.valInPoint(poly.odds, point, poly.degree) << endl;
	cout << poly.valInPoint(poly.oddsDer, point, poly.degree-1) << endl;



	polynomial poly2;
	string stringInput2;
	cin >> stringInput2;
	poly2.inputf(stringInput2);
	

	cout << poly.outputf(poly.sum(poly2), max(poly.degree, poly2.degree)) << endl;

	cout << poly.outputf(poly.residual(poly2), max(poly.degree, poly2.degree)) << endl;

	cout << poly.outputf(poly.multipl(poly2), poly.degree + poly2.degree - 1) << endl;

	cout << poly.outputf(poly.divis(poly2), poly.degree - poly2.degree + 1) << endl;
}
	
