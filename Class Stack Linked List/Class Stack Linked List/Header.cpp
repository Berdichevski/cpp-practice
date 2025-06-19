#include "Header.h"
#include <iostream>
using namespace std;

Stack::Node::Node()
{
}

Stack::Node::Node(int data)
{
}

Stack::Node::Node(int data, Node* Next)
{
}

void Stack::push(int data)
{
	Node* p = new Node;
	p->data = data;
	p->prev = top;
	top = p;

	if (top->prev != nullptr)
	{
		if (data > top->prev->currentMax)
		{
			top->currentMax = data;
		}
		else
		{
			top->currentMax = top->prev->currentMax;
		}
	}
	else
	{
		top->currentMax = data;
	}
}

int Stack::peek()
{
	if (isEmpty())
	{
		return top->data;
	}
	else
	{
		cout << "Stack is empty!";
	}
}

int Stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty!";
	}
	else
	{
		int ans = top->data;
		top = top->prev;
		return ans;
	}
}

bool Stack::isEmpty()
{
	return (top == nullptr);
}

int Stack::getMax()
{
	return top->currentMax;
}

Stack::Stack()
{
	top = nullptr;
}

