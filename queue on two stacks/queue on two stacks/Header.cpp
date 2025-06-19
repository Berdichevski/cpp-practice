#include "Header.h"
#include <iostream>
using namespace std;

Node* Stack::getHead()
{
    return this->head;
}

Stack::Stack()
{
    head = nullptr;
}

void Stack::push(int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = head;
    head = node;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    int value = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;
    return value;
}

bool Stack::isEmpty()
{
    return head == nullptr;
}

void Queue::push(int elem)
{
    s1.push(elem);
}

int Queue::pop()
{
    if (s2.isEmpty())
    {
        while (!s1.isEmpty())
        {
            s2.push(s1.getHead()->value);
            s1.pop();
        }
    }
    int head = s2.getHead()->value;
    s2.pop();
    return head;
}
