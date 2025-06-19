#include "Header.h"

Word::Word() : word(""), Next(nullptr) {}

Word::Word(string word) : word(word), Next(nullptr) {}

void Word::setNext(Word* n)
{
	this->Next = n;
}

Word* Word::getNext()
{
	return this->Next;
}

string Word::getWord()
{
	return this->word;
}

Sentence::Sentence() : Head(nullptr), Tail(nullptr), Next(nullptr) {}

Sentence::Sentence(string sentence) : Head(nullptr), Tail(nullptr), Next(nullptr) {}

void Sentence::setNext(Sentence* n)
{
	this->Next = n;
}

Sentence* Sentence::getNext()
{
	return this->Next;
}

void Sentence::Clean()
{
	this->Head = nullptr;
	this->Tail = nullptr;
}

void Sentence::Append(string word)
{
	Word* n = new Word(word);
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

Word* Sentence::getHead()
{
	return this->Head;
}

Word* Sentence::getTail()
{
	return this->Tail;
}

void Sentence::setHead(Word* head)
{
	this->Head = head;
}

void Sentence::setTail(Word* tail)
{
	this->Tail = tail;
}

Text::Text() : Head(nullptr), Tail(nullptr) {}

void Text::CopyAndAppend(Sentence sentence)
{
	Sentence* n = new Sentence();

	Word* i = sentence.getHead();
	while (i != nullptr) {
		//cout << i->getWord() << " ";
		n->Append(i->getWord());
		i = i->getNext();
	}

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

Sentence* Text::getHead()
{
	return this->Head;
}

Sentence* Text::getTail()
{
	return this->Tail;
}
