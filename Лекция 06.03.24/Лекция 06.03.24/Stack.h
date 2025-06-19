#pragma once

class Stack
{
public:
	Stack();
	~Stack();

	void Push(int element);
	int Pop();
	int Peek();
};