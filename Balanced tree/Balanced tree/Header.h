#pragma once
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
public:
    Node* getRoot() { return pRoot; }
    BinaryTree();
    BinaryTree(Node* n) : pRoot(n) {};
    ~BinaryTree();
    void Add(int Value);
    void printTree(Node* pNode);
    int height(Node* root);
    bool isBalanced(Node* root);
};