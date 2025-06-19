#include "Header.h"

Node::Node() : el(0), next(nullptr), friends(nullptr) {}
List::List() : head(nullptr) {}

void List::Append(int el) 
{
    Node* newNode = new Node();
    newNode->el = el;
    newNode->next = nullptr;
    newNode->friends = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* List::getHead() { return this->head; }
BigNode* BigList::getHead() { return this->head; }

bool isfull(BigList a)
{
    int n = -1;
    for (BigNode* i = a.getHead(); i != nullptr; i = i->next) {
        n++;
    }
    for (BigNode* i = a.getHead(); i != nullptr; i = i->next) {
        int temp = 0;
        for (Node* j = i->el.getHead(); j != nullptr; j = j->next) {
            temp++;
        }
        if (n != temp) {
            return 0;
        }
    }
    return 1;
}

BigNode::BigNode() : el(), next(nullptr) {}

BigNode::BigNode(List el) : el(el), next(nullptr) {}

BigList::BigList() : head(nullptr) {}

void BigList::Append(List el) {
    // Implement the Append function to add a new element to the BigList
    BigNode* newNode = new BigNode(el);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        BigNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

