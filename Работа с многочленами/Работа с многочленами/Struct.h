#pragma once
#include <iostream>
using namespace std;

struct polynomial {
	int* inputf(string polynomial);
	string outputf(int* odds, int deg);
	int* derivativeOdds(int* odds);
	int valInPoint(int* odds, int point, int deg);
	int* sum(polynomial poly2);
	int* residual(polynomial poly2);
	int* multipl(polynomial poly2);
	int* divis(polynomial poly2);
	int degree;
	int* odds;
	int* oddsDer;
};
