#include <iostream>
#include <algorithm>

using namespace std;

struct Node 
{
    int value;
    Node* next;
};

class Stack 
{
private:
    Node* head;
public:
    Node* getHead();
    Stack();
    void push(int value);
    int pop();
    bool isEmpty();
};


class Queue 
{
private:
    Stack s1;
    Stack s2;
public:
    void push(int elem);
    int pop();
};

