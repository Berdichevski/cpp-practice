#pragma once
#include <iostream>
using namespace std;

class Stack {
private:
    int maxSize;
    char* items;
    int top;

public:
    Stack(int maxSize);
    Stack();
    void push(char c);
    char pop();
    char peek();
    bool isEmpty();
};

