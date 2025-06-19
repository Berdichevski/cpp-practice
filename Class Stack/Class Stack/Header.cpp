#include "Header.h"
#include <iostream>
using namespace std;

Stack::Stack(int maxSize)
{
    this->maxSize = maxSize;
    this->items = new char[this->maxSize] {' '};
    top = -1;
}

Stack::Stack()
{
    this->maxSize = 0;
    this->items = nullptr;
    top = -1;
}

void Stack::push(char c)
{
    if (top == maxSize - 1)
    {
        cout << "Stack overflow!" << endl;
        return;
    }
    items[++top] = c;
}

char Stack::pop()
{
    if (top == -1) {
        cout << "Empty stack!" << endl;
        return ' ';
    }
    return items[top--];
}

char Stack::peek()
{
    if (top == -1) {
        cout << "Empty stack!" << endl;
        return ' ';
    }
    return items[top];
}

bool Stack::isEmpty()
{
    return top == -1;
}











