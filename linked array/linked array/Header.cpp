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
}

Node* List::getHead() { return Head; };

Node* List::getTail() { return Tail; }

Node* List::reverseLinkedList() 
{
	Node* prev = nullptr;
	Node* current = Head;
	Node* next = nullptr;

	Tail = Head; 
	while (current->getNext() != nullptr) {
		next = current->getNext();
		current->setNext(prev);
		prev = current;
		current = next;
	}

	Head = prev; 

	return Head;
}

