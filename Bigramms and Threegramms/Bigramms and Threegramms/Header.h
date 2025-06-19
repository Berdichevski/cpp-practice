#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Word
{
	string word;
	Word* Next;
	bool foundBigrammEnd;
	bool foundThreegrammEnd;
public:
	Word();
	Word(string word);
	void setNext(Word* n);
	Word* getNext();
	string getWord();
	bool getFoundBigrammEnd();
	bool getFoundThreegrammEnd();
	void raiseFoundBigrammEnd();
	void raiseFoundThreegrammEnd();
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
	Sentence* getHeadT();
	Sentence* getTailT();
	void mostFrequentBigrammEnd(Word* start);
	void mostFrequentThreegrammEnd(Word* start);
};

class End
{
	string end;
	int frequency;
	End* Next;
public:
	End();
	End(string end);
	void setNext(End* n);
	End* getNext();
	string getEnd();
	int getFrequency();
	void addFrequency();
};

class EndsList
{
	End* Head;
	End* Tail;
public:
	EndsList();
	void Append(string end);
	End* getHead();
	End* getTail();
	void setHead(End* head);
	void setTail(End* tail);
};