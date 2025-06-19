#include "Header.h"
#include <iostream>
#include <queue>
using namespace std;

BinaryTree::BinaryTree() : pRoot(nullptr) {};

BinaryTree::~BinaryTree() {}

void BinaryTree::Add(int Value)
{
    Node* pCurrent = pRoot;
    Node* pParent = nullptr;

    while (pCurrent != nullptr)
    {
        if (Value == pCurrent->Value)
        {
            return;
        }

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

void BinaryTree::printTree(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node* current = q.front();
            q.pop();

            cout << current->Value << " ";

            if (current->pLeft)
            {
                q.push(current->pLeft);
            }

            if (current->pRight)
            {
                q.push(current->pRight);
            }
        }

        cout << endl;
    }
}

void BinaryTree::minLeafValue(Node* pNode, int& minValue)
{
    if ((pNode->pLeft == nullptr) && (pNode->pRight == nullptr))
    {
        if (pNode->Value < minValue)
        {
            minValue = pNode->Value;
        }
    }
    else
    {
        if (pNode->pLeft != nullptr)
        {
            minLeafValue(pNode->pLeft, minValue);
        }
        if (pNode->pRight != nullptr)
        {
            minLeafValue(pNode->pRight, minValue);
        }
    }
}

Node::Node() :Value(0), pLeft(nullptr), pRight(nullptr) {}

Node::Node(int val) :Value(val), pLeft(nullptr), pRight(nullptr) {};

