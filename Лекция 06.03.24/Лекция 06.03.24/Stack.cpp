#include "stack.h"

Stack::Stack()
{
	pData = new int(100);
	int size = 0;
}

Stack::~Stack()
{

}

void Stack::Push(int element)
{
}

int Stack::Pop()
{
	//not empty
	return pData[size-1];
}

int Stack::Peek()
{
	int element = Peek();
	--size;
	return element;
}
