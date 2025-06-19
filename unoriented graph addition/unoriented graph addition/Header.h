#pragma once
using namespace std;
struct Node {
	int el;
	Node* next;
	Node* friends;
	Node();
};

class List {
private:
	Node* head;
public:
	List();
	void Append(int el);
	Node* getHead();
};

struct BigNode {
	List el;
	BigNode* next;

	BigNode();
	BigNode(List el);
};

class BigList {
private:
	BigNode* head;
public:
	BigList();
	void Append(List el);
	BigNode* getHead();
};

bool isfull(BigList a);