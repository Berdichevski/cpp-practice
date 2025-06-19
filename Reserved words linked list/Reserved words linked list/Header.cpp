#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Node::Node() :word(""), Next(nullptr), inclusions(0) {};

Node::Node(string word) : word(word), Next(nullptr), inclusions(0) {}

void Node::setNext(Node* n)
{
	this->Next = n;
}

Node* Node::getNext()
{
	return Next;
}

void Node::setWord(string word)
{
    this->word = word;
}

string Node::getWord()
{
	return word;
}

void Node::addInclusion()
{
	this->inclusions++;
}

void Node::setInclusions(int inclusions)
{
    this->inclusions = inclusions;
}

int Node::getInclusions()
{
	return inclusions;
}

List::List() : Head(nullptr), Tail(nullptr) {};

void List::Append(string word)
{
	Node* n = new Node(word);
	if (Head == nullptr)
	{
		Head = Tail = n;
	}
	else
	{
		Tail->setNext(n);
		Tail = n;
	}
}

Node* List::getHead() { return Head; };

Node* List::getTail() { return Tail; }

void List::Sort()
{
    if (Head == nullptr || Head->getNext() == nullptr)
    {
        cout << "Unable to sort!";
        return;
    }

    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        Node* i = Head;

        while (i->getNext() != nullptr)
        {
            if (i->getInclusions() < i->getNext()->getInclusions())
            {
                string tempWord = i->getWord();
                int tempInclusions = i->getInclusions();

                i->setWord(i->getNext()->getWord());
                i->setInclusions(i->getNext()->getInclusions());

                i->getNext()->setWord(tempWord);
                i->getNext()->setInclusions(tempInclusions);

                swapped = true;
            }
            i = i->getNext();
        }
    }
}

void List::checkAndAdd(string word)
{
    Node* i = Head;

    while (i != nullptr)
    {
        if (i->getWord() == word)
        {
            i->addInclusion();
        }
        i = i->getNext();
    }
}



