#pragma once
using namespace std;

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
    void findDevidableElement(Node* pNode);
};