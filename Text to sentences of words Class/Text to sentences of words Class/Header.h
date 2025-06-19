#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Word
{
	string word;
	Word* Next;
public:
	Word();
	Word(string word);
	void setNext(Word* n);
	Word* getNext();
	string getWord();
};

class Sentence
{
	Word* Head;
	Word* Tail;

	Sentence* Next;
public:
	Sentence();
	Sentence(string sentence);
	void Append(string word);
	Word* getHead();
	Word* getTail();
	void setHead(Word* head);
	void setTail(Word* tail);

	void setNext(Sentence* n);
	Sentence* getNext();
	void Clean();
};

class Text 
{
	Sentence* Head;
	Sentence* Tail;
public:
	Text();
	void CopyAndAppend(Sentence sentence);
	Sentence* getHead();
	Sentence* getTail();
};