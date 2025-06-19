#include "Header.h"

Word::Word() : word(""), Next(nullptr), foundBigrammEnd(0), foundThreegrammEnd(0) {}

Word::Word(string word) : word(word), Next(nullptr), foundBigrammEnd(0), foundThreegrammEnd(0) {}

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

bool Word::getFoundBigrammEnd()
{
	return this->foundBigrammEnd;
}

bool Word::getFoundThreegrammEnd()
{
	return this->foundThreegrammEnd;
}

void Word::raiseFoundBigrammEnd()
{
	this->foundBigrammEnd = 1;
}

void Word::raiseFoundThreegrammEnd()
{
	this->foundThreegrammEnd = 1;
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

Sentence* Text::getHeadT()
{
	return this->Head;
}

Sentence* Text::getTailT()
{
	return this->Tail;
}

EndsList::EndsList() : Head(nullptr), Tail(nullptr) {}

void EndsList::Append(string end)
{
	End* n = new End(end);
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

End* EndsList::getHead()
{
	return this->Head;
}

End* EndsList::getTail()
{
	return this->Tail;
}

void EndsList::setHead(End* head)
{
	this->Head = head;
}

void EndsList::setTail(End* tail)
{
	this->Tail = tail;
}

End::End() : end(""), frequency(1), Next(nullptr) {};

End::End(string end) : end(end), frequency(1), Next(nullptr) {};

void End::setNext(End* n)
{
	this->Next = n;
}

End* End::getNext()
{
	return this->Next;
}

string End::getEnd()
{
	return this->end;
}

int End::getFrequency()
{
	return this->frequency;
}

void End::addFrequency()
{
	this->frequency++;
}


void Text::mostFrequentBigrammEnd(Word* start)
{
	Sentence* j = this->getHeadT();
	Word* i = j->getHead();

	EndsList* ends = new EndsList();
	int maxFrequency = 1;
	string endWithMaxFrequency = "";

	while (j != nullptr)
	{
		while (i->getNext() != nullptr)
		{
			if (i == start)
			{
				bool stored = 0;
				End* k = ends->getHead();
				while ((k != nullptr) && !stored)
				{
					if (k->getEnd() == i->getNext()->getWord())
					{
						k->addFrequency();
						stored = 1;
						if (maxFrequency < k->getFrequency())
						{
							maxFrequency = k->getFrequency();
							endWithMaxFrequency = k->getEnd();
						}
						if (maxFrequency == k->getFrequency())
						{
							if (k->getEnd() <= endWithMaxFrequency)
							{
								endWithMaxFrequency = k->getEnd();
							}
						}
					}
					k = k->getNext();
				}
				if (!stored)
				{
					ends->Append(i->getNext()->getWord());
					stored = 1;
					if (maxFrequency == 1)
					{
						if (endWithMaxFrequency == "")
						{
							endWithMaxFrequency = ends->getTail()->getEnd();
						}
						else if (ends->getTail()->getEnd() <= endWithMaxFrequency)
						{
							endWithMaxFrequency = ends->getTail()->getEnd();
						}
					}
				}

			}
			i = i->getNext();
		}
		j = j->getNext();
		if (j != nullptr)
		{
			i = j->getHead();
		}
	}

	cout << start->getWord() << " " << endWithMaxFrequency;
	start->raiseFoundBigrammEnd();
}

void Text::mostFrequentThreegrammEnd(Word* start)
{
	Sentence* j = this->getHeadT();
	Word* i = j->getHead();

	EndsList* ends = new EndsList();
	int maxFrequency = 1;
	string endWithMaxFrequency = "";

	while (j != nullptr)
	{
		while ((i->getNext() != nullptr) && (i->getNext()->getNext() != nullptr))
		{
			if (i == start)
			{
				bool stored = 0;
				End* k = ends->getHead();
				while ((k != nullptr) && !stored)
				{
					if (k->getEnd() == i->getNext()->getWord() + " " + i->getNext()->getNext()->getWord())
					{
						k->addFrequency();
						stored = 1;
						if (maxFrequency < k->getFrequency())
						{
							maxFrequency = k->getFrequency();
							endWithMaxFrequency = k->getEnd();
						}
						if (maxFrequency == k->getFrequency())
						{
							if (k->getEnd() <= endWithMaxFrequency)
							{
								endWithMaxFrequency = k->getEnd();
							}
						}
					}
					k = k->getNext();
				}
				if (!stored)
				{
					ends->Append(i->getNext()->getWord() + " " + i->getNext()->getNext()->getWord());
					stored = 1;
					if (maxFrequency == 1)
					{
						if (endWithMaxFrequency == "")
						{
							endWithMaxFrequency = ends->getTail()->getEnd();
						}
						else if (ends->getTail()->getEnd() <= endWithMaxFrequency)
						{
							endWithMaxFrequency = ends->getTail()->getEnd();
						}
					}
				}

			}
			i = i->getNext();
		}
		j = j->getNext();
		if (j != nullptr)
		{
			i = j->getHead();
		}
	}
	/*cout << "------------------" << endWithMaxFrequency << endl;
	cout << "-------" << start->getWord() << endl;*/
	cout << start->getWord() << " " << endWithMaxFrequency;
	start->raiseFoundThreegrammEnd();
}