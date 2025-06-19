#pragma once
#include <limits.h>
using namespace std;

struct Node
{
    Node();
    Node(int val);
    int Value;
    Node* pLeft;
    Node* pRight;
};

class BinaryTree
{
private:
    Node* pRoot;
    int maxValue;
public:
    int getMaxVal() { return maxValue; }
    Node* getRoot() { return pRoot; }
    BinaryTree() : pRoot(nullptr), maxValue(INT_MIN) {};
    BinaryTree(Node* n) : pRoot(n), maxValue(INT_MIN) {};
    ~BinaryTree();
    void Add(int Value);
    void countMaxIncludings(Node* root, int& counter);
};