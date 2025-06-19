#include "Header.h"
using namespace std;

message::message() : data(""), nLevel(0), next(nullptr) {}
message::message(string mes, int nLev) : data(mes), nLevel(nLev), next(nullptr) {}

ListMessages::ListMessages() : head(nullptr), tail(nullptr) {}

void ListMessages::append(string mes, int nLev)
{
	message* n = new message(mes, nLev);
	if (this->head == nullptr) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->next = n;
		this->tail = n;
	}
}

message* ListMessages::getHead()
{
	return head;
}

message* ListMessages::getTail()
{
	return tail;
}