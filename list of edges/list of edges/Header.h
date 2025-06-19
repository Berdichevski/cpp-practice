#pragma once
#include <iostream>
using namespace std;

struct edge
{
	edge();
	edge(string text);

	string data;
	edge* next;
};

class ListEdges
{
public:
	ListEdges();
	void append(string text);
	edge* getHead();
	edge* getTail();

private:
	edge* head;
	edge* tail;
};