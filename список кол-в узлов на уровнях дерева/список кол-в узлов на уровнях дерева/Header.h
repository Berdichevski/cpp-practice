#pragma once
using namespace std;

struct ListNode
{
    ListNode(int val) : value(val), next(nullptr) {};
    int value;
    ListNode* next;
};

class List
{
private:
    ListNode* Head;
    ListNode* Tail;
public:
    List() : Head(nullptr), Tail(nullptr) {};
    void Append(int value);
    ListNode* getHead();
    ListNode* getTail();
    void printList();
};

struct Node 
{
    int Value;
    Node* pLeft;
    Node* pRight;
};

class BinaryTree 
{
private:
    Node* pRoot;
public:
    Node* getRoot() { return pRoot; }
    BinaryTree();
    ~BinaryTree();
    void printTree(Node* root);
    void Add(int Value);
    List ListOfLengths(Node* root);
};

