#include "Header.h"
#include <iostream>
#include <fstream>
using namespace std;

Node::Node() :number(), Next(nullptr) {};

Node::Node(int number) : number(number), Next(nullptr) {}

void Node::setNext(Node* n)
{
	this->Next = n;
}

Node* Node::getNext()
{
	return Next;
}

int Node::getNumber()
{
	return number;
}

void Node::deleteNextNode()
{
	this->setNext(getNext()->getNext());
}

List::List() : Head(nullptr), Tail(nullptr) {};

void List::Append(int number)
{
	Node* n = new Node(number);
	if (Head == nullptr)
	{
		Head = Tail = n;
	}
	else
	{
		Tail->setNext(n);
		Tail = n;
	}
	n->setNext(Head);
}

Node* List::getHead() { return Head; };

Node* List::getTail() { return Tail; }

void List::setHead(Node* a)
{
	this->Head = a;
}



