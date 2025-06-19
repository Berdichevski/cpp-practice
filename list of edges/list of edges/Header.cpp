#include "Header.h"
#include <string>

using namespace std;

edge::edge() : data(""), next(nullptr) {}

edge::edge(string text) : data(text), next(nullptr) {}

ListEdges::ListEdges() : head(nullptr), tail(nullptr) {}

void ListEdges::append(string text)
{
	edge* n = new edge(text);
	if (this->head == nullptr) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->next = n;
		this->tail = n;
	}
}

edge* ListEdges::getHead()
{
	return head;
}

edge* ListEdges::getTail()
{
	return tail;
}
