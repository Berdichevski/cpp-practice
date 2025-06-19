#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct incidenceCol
{
	incidenceCol();
	incidenceCol(int a, int b, int numVerticies);

	bool* data;
	incidenceCol* next;
};

class IncidenceMatrix
{
public:
	IncidenceMatrix();
	void append(int a, int b, int numVerticies);
	incidenceCol* getHead();
	incidenceCol* getTail();
	void printMatrix(int numVerticies);

private:
	incidenceCol* head;
	incidenceCol* tail;
};