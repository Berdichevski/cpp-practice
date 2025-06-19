#include "Header.h"

using namespace std;

incidenceCol::incidenceCol() :data(nullptr), next(nullptr) {}

incidenceCol::incidenceCol(int a, int b, int numVerticies) :next(nullptr)
{
	data = new bool[numVerticies] {0};
	data[a] = 1;
	data[b] = 1;
}

IncidenceMatrix::IncidenceMatrix() :head(nullptr), tail(nullptr) {}

void IncidenceMatrix::append(int a, int b, int numVerticies)
{
	incidenceCol* column = new incidenceCol(a, b, numVerticies);
	if (this->head == nullptr) {
		this->head = column;
		this->tail = column;
	}
	else {
		this->tail->next = column;
		this->tail = column;
	}
}

incidenceCol* IncidenceMatrix::getHead()
{
	return head;
}

incidenceCol* IncidenceMatrix::getTail()
{
	return tail;
}

void IncidenceMatrix::printMatrix(int numVerticies)
{
	for (int i = 0; i < numVerticies; i++)
	{
		incidenceCol* n = getHead();
		while (n != nullptr)
		{
			cout << n->data[i] << " ";
			n = n->next;
		}
		cout << endl;
	}
	cout << endl;
}


