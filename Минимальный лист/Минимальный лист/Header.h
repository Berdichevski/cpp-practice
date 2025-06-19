#pragma once
using namespace std;

struct Node {
    int Value;
    Node* pLeft;
    Node* pRight;
    Node();
    Node(int val);
};

class BinaryTree {
private:
    Node* pRoot;
public:
    Node* getRoot() { return pRoot; }
    BinaryTree();
    ~BinaryTree();
    void Add(int Value);
    void printTree(Node* root);
    void minLeafValue(Node* pNode, int& minValue);
};