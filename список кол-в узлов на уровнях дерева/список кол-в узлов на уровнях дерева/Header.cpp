#include "Header.h"
#include <iostream>
#include <queue>
using namespace std;

BinaryTree::BinaryTree() : pRoot(nullptr) {};

BinaryTree::~BinaryTree() {}

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

List BinaryTree::ListOfLengths(Node* root)
{
    List result;

    if (root == nullptr)
    {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        result.Append(levelSize);

        for (int i = 0; i < levelSize; i++)
        {
            Node* current = q.front();
            q.pop();

            if (current->pLeft)
            {
                q.push(current->pLeft);
            }

            if (current->pRight)
            {
                q.push(current->pRight);
            }
        }
    }
    return result;
}

void List::Append(int value)
{
    ListNode* n = new ListNode(value);
    if (Head == nullptr)
    {
        Head = Tail = n;
    }
    else
    {
        Tail->next = n;
        Tail = n;
    }
}

ListNode* List::getHead()
{
    return Head;
}

ListNode* List::getTail()
{
    return Tail;
}

void List::printList()
{
    ListNode* i = getHead();
    while (i != nullptr)
    {
        cout << i->value << " ";
        i = i->next;
    }
    cout << endl;
}