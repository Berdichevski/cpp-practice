#include "Header.h"
#include <iostream>
#include <queue>
using namespace std;

BinaryTree::~BinaryTree() {}

void BinaryTree::Add(int Value)
{
    if (Value > maxValue)
    {
        maxValue = Value;
    }

    Node* pCurrent = pRoot;
    Node* pParent = nullptr;

    while (pCurrent != nullptr)
    {
        pParent = pCurrent;
        if (Value < pCurrent->Value)
            pCurrent = pCurrent->pLeft;
        else
            pCurrent = pCurrent->pRight;
    }

    Node* pNew = new Node();
    pNew->Value = Value;
    pNew->pLeft = nullptr;
    pNew->pRight = nullptr;

    if (pParent == nullptr)
    {
        pRoot = pNew;
        return;
    }

    if (Value < pParent->Value)
        pParent->pLeft = pNew;
    else
        pParent->pRight = pNew;
}

void BinaryTree::countMaxIncludings(Node* root, int& counter)
{
    if (root == nullptr) 
    {
        return;
    }

    countMaxIncludings(root->pLeft, counter);
    if (root->Value == getMaxVal())
    {
        counter++;
    }
    countMaxIncludings(root->pRight, counter);
}

Node::Node() :Value(0), pLeft(nullptr), pRight(nullptr) {}

Node::Node(int val) :Value(val), pLeft(nullptr), pRight(nullptr) {};

