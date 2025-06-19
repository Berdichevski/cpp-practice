#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Node
{
	int number;
	Node* Next;
public:
	Node();
	Node(int number);
	void setNext(Node* n);
	Node* getNext();
	int getNumber();
};

class List
{
	Node* Head;
	Node* Tail;
public:
	List();
	void Append(int number);
	Node* getHead();
	Node* getTail();
	Node* reverseLinkedList();
};

