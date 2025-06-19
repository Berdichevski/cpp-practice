#pragma once
#include <iostream>
#include <fstream>
using namespace std;

//--------------------------------------------------------------

struct word
{
	word();
	word(string word);

	string data;
	word* next;
};

class ListWords
{
public:
	ListWords();
	void append(string word);
	word* getHead();
	word* getTail();

private:
	word* head;
	word* tail;
};

//--------------------------------------------------------------

struct sentence
{
	sentence();
	sentence(string sentence);

	ListWords data;
	sentence* next;
	string sen;
};

class ListSentences
{
public:
	ListSentences();
	void append(string sentence);
	sentence* getHead();
	sentence* getTail();

private:
	sentence* head;
	sentence* tail;
};

//--------------------------------------------------------------

struct gramm
{
	gramm();
	gramm(string end, string next);
	void add(string end);
	void sorted();
	int min(int* arr, string* ar, int j, int n);

	string data;
	gramm* next;
	string* post;
	int* freq;
	int n;
};

class ListGramms
{
public:
	ListGramms();
	void append(string end, string next);
	gramm* getHead();
	gramm* getTail();
	void pop(gramm* end, gramm* start);
	void sort();

private:
	gramm* head;
	gramm* tail;
};

//---------------------------------------------------------------

struct nextWord
{
	nextWord();
	nextWord(string beg, string end);

	string phraseBeginning;
	string phraseEnding;
	nextWord* nextNode;
};

class NextWords
{
public:
	NextWords();
	void append(string beg, string end);
	nextWord* getHead();
	nextWord* getTail();
	string textExtension(string phraseBeginning, int wordsCount);
private:
	nextWord* head;
	nextWord* tail;
};