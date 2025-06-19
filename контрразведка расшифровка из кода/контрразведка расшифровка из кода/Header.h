#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct message
{
	message();
	message(string mes, int nLev);

	string data;
	int nLevel;
	message* next;
};

class ListMessages
{
public:
	ListMessages();
	void append(string mes, int nLev);
	message* getHead();
	message* getTail();

private:
	message* head;
	message* tail;
};