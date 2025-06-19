#pragma once
#include <iostream>
using namespace std;

class Stack {
private:
	struct Node {
		Node* prev;
		int data;
		int currentMax;
		Node();
		Node(int data);
		Node(int data, Node* Next);
	};
	Node* top;
public:
	void push(int data);
	int peek();
	int pop();
	bool isEmpty();
	int getMax();
	Stack();
};