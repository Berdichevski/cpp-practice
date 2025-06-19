#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Node
{
	int degree;
	double coefficient;
	Node* Next;
	bool flagOverlap;
public:
	Node();
	Node(int degree, double coefficient);
	void setNext(Node* n);
	Node* getNext();
	int getDegree();
	double getCoefficient();
	void setFlagOverlap();
	bool getFlagOverlap();
};

class List
{
	Node* Head;
	Node* Tail;
public:
	List();
	void Append(int degree, double coefficient);
	Node* getHead();
	Node* getTail();
	List* sumPolynominals(List* poly2);
	List* derivative();
	List* operator = (List* poly2);
	void printList();
};

