#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
	string word;
	int inclusions;
	Node* Next;
public:
	Node();
	Node(string word);
	void setNext(Node* n);
	Node* getNext();
	void setWord(string word);
	string getWord();
	void addInclusion();
	void setInclusions(int inclusions);
	int getInclusions();
};

class List
{
	Node* Head;
	Node* Tail;
public:
	List();
	void Append(string word);
	Node* getHead();
	Node* getTail();
	void Sort();
	void checkAndAdd(string word);
};

