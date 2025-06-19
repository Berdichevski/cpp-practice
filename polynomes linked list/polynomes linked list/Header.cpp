#include "Header.h"
#include <iostream>
#include <fstream>
using namespace std;

Node::Node() :degree(), coefficient(), Next(nullptr), flagOverlap(0) {};

Node::Node(int degree, double coefficient) : degree(degree), coefficient(coefficient), flagOverlap(0), Next(nullptr) {}

void Node::setNext(Node* n)
{
	this->Next = n;
}

Node* Node::getNext()
{
	return Next;
}

int Node::getDegree()
{
	return degree;
}

double Node::getCoefficient()
{
	return coefficient;
}

void Node::setFlagOverlap()
{
	this->flagOverlap = 1;
}

bool Node::getFlagOverlap()
{
	return this->flagOverlap;
}

List::List() : Head(nullptr), Tail(nullptr) {};

void List::Append(int degree, double coefficient)
{
	Node* n = new Node(degree, coefficient);
	if (Head == nullptr)
	{
		Head = Tail = n;
	}
	else
	{
		Tail->setNext(n);
		Tail = n;
	}
}

Node* List::getHead() { return Head; };

Node* List::getTail() { return Tail; }

List* List::sumPolynominals(List* poly2)
{
	List* result = new List();
	Node* i = this->getHead();

	while (i != nullptr)
	{
		int tempDegree = i->getDegree();
		Node* j = poly2->getHead();
		bool flagBothContain = 0;
		while (j != nullptr)
		{
			if (j->getDegree() == tempDegree)
			{
				flagBothContain = 1;
				result->Append(j->getDegree(), i->getCoefficient() + j->getCoefficient());
				j->setFlagOverlap();
			}
			j = j->getNext();
		}
		if (flagBothContain == 0)
		{
			result->Append(i->getDegree(), i->getCoefficient());
		}
		i = i->getNext();
	}

	i = poly2->getHead();

	while (i != nullptr)
	{
		if (i->getFlagOverlap() == 0)
		{
			result->Append(i->getDegree(), i->getCoefficient());
		}
		i = i->getNext();
	}

	return result;
}

List* List::derivative()
{
	List* result = new List();
	Node* i = this->getHead();

	while (i != nullptr)
	{
		result->Append(i->getDegree() - 1, i->getDegree() * i->getCoefficient());
		i = i->getNext();
	}

	return result;
}

List* List::operator=(List* poly2)
{
	List* n = new List();

	Node* i = poly2->getHead();
	while (i != nullptr) {
		n->Append(i->getDegree(),i->getCoefficient());
		i = i->getNext();
	}
	return n;
}

void List::printList()
{
	Node* i = this->getHead();
	while (i != nullptr)
	{
		if (i->getNext() != nullptr)
		{
			cout << i->getCoefficient() << "x^" << i->getDegree() << " + ";
		}
		else
		{
			cout << i->getCoefficient() << "x^" << i->getDegree();
		}

		i = i->getNext();
	}
	cout << endl;
}



