#include "Header.h"

using namespace std;

word::word() : data(""), next(nullptr) {}

word::word(string word) : data(word), next(nullptr) {}

sentence::sentence() : sen(""), next(nullptr) {}

sentence::sentence(string sentence) : sen(sentence), next(nullptr) {}

gramm::gramm() : data(""), next(nullptr), n(0), freq(nullptr), post(nullptr) {}

gramm::gramm(string end, string next) : data(end), next(nullptr), n(1) {
	int* q = new int [1] {1};
	freq = q;
	string* w = new string[1]{ next };
	post = w;
}

void gramm::add(string end)
{
	n++;
	int* a = new int[n];
	for (int i = 0; i < n - 1; i++)
		a[i] = freq[i];
	a[n - 1] = 1;
	freq = a;
	string* npost = new string[n + 1];
	for (int i = 0; i < n - 1; i++)
		npost[i] = post[i];
	npost[n - 1] = end;
	post = npost;
}

void gramm::sorted()
{
	for (int i = 0; i < this->n; i++) {
		int smallestPosition = gramm().min(this->freq, this->post, i, n);
		swap(this->freq[i], this->freq[smallestPosition]);
		swap(this->post[i], this->post[smallestPosition]);
	}
}
int gramm::min(int* arr, string* ar, int j, int n)
{
	int min = j;

	for (int i = j; i < n; i++)
	{
		if (arr[i] > arr[min])
			min = i;
		if (arr[i] == arr[min]) {
			if (ar[i] < ar[min])
				min = i;
		}

	}
	return min;
}

ListWords::ListWords() : head(nullptr), tail(nullptr) {}

void ListWords::append(string Word)
{
	word* n = new word(Word);
	if (this->head == nullptr) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->next = n;
		this->tail = n;
	}
}

word* ListWords::getHead()
{
	return head;
}

word* ListWords::getTail()
{
	return tail;
}

ListSentences::ListSentences() : head(nullptr), tail(nullptr) {}

void ListSentences::append(string Sentence)
{
	sentence* n = new sentence(Sentence);

	int i = 0;
	bool f = 0;
	string st = "";
	while (i < Sentence.size()) {
		if (Sentence[i] == ' ' && f) {
			f = 0;
			n->data.append(st);
			st = "";
		}
		else {
			if (Sentence[i] != ' ' && Sentence[i] != '.') {
				st += Sentence[i];
				f = 1;
			}
		}
		i++;
	}
	n->data.append(st);
	if (this->head == nullptr) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->next = n;
		this->tail = n;
	}
}

sentence* ListSentences::getHead()
{
	return head;
}

sentence* ListSentences::getTail()
{
	return tail;
}

ListGramms::ListGramms() : head(nullptr), tail(nullptr) {}

void ListGramms::append(string end, string next)
{
	gramm* n = new gramm(end, next);
	if (this->head == nullptr) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->next = n;
		this->tail = n;
	}
}

gramm* ListGramms::getHead()
{
	return head;
}

gramm* ListGramms::getTail()
{
	return tail;
}

void ListGramms::pop(gramm* end, gramm* start)
{
	while (start->next != end)
		start = start->next;
	start->next = end->next;
}

void ListGramms::sort()
{
	for (gramm* i = this->getHead(); i != nullptr; i = i->next) {
		i->sorted();
	}
}

nextWord::nextWord() : phraseBeginning(""), phraseEnding(""), nextNode(nullptr) {}

nextWord::nextWord(string beg, string end) : phraseBeginning(beg), phraseEnding(end), nextNode(nullptr) {}

NextWords::NextWords() : head(nullptr), tail(nullptr) {}

void NextWords::append(string beg, string end)
{
	nextWord* n = new nextWord(beg, end);
	if (this->head == nullptr) 
	{
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->nextNode = n;
		this->tail = n;
	}
}

nextWord* NextWords::getHead()
{
	return this->head;
}

nextWord* NextWords::getTail()
{
	return this->tail;
}

string NextWords::textExtension(string phraseBeginning, int wordsCount)
{
	//считаем изначальную длину начала
	int phraseBeginning_wordsCounter = 1;
	for (int j = 0; j < phraseBeginning.length(); j++)
	{
		if (phraseBeginning[j] == ' ')
		{
			phraseBeginning_wordsCounter++;
		}
	}

	//пошли дописывать
	for (int i = 0; i < wordsCount; i++)
	{
		bool flagExtended = 0;

		//вытаскиваем последнее слово
		int l = phraseBeginning.length() - 1;
		string lastWord = "";
		while ((l >= 0) && (phraseBeginning[l] != ' '))
		{
			lastWord = phraseBeginning[l] + lastWord;
			l -= 1;
		}

		//вытаскиваем последнюю пару слов
		l = phraseBeginning.length() - 1;
		string twoLastWords = "";
		int wordCounter = 0;
		while ((l >= 0) && (wordCounter < 2))
		{
			if (phraseBeginning[l] != ' ')
			{
				twoLastWords = phraseBeginning[l] + twoLastWords;
			}
			else
			{
				wordCounter++;
			}
			l -= 1;
		}

		//если фраза содержит как минимум два слова, идем по словарю и ищем продолжение
		if (phraseBeginning_wordsCounter > 1)
		{
			nextWord* k = this->getHead();
			while (k != nullptr)
			{
				if (twoLastWords == k->phraseBeginning)
				{
					phraseBeginning += " " + k->phraseEnding;
					//отмечаем, что слово добавлено
					flagExtended = 1;
					break;
				}
				k = k->nextNode;
			}
		}

		//если предыдущий вариант не отработал и слово не добавлено, идем по списку - 
		// ищем продолжение к последнему слову
		if (!flagExtended)
		{
			nextWord* k = this->getHead();
			while (k != nullptr)
			{
				if (lastWord == k->phraseBeginning)
				{
					phraseBeginning += " " + k->phraseEnding;
					//отмечаем, что слово добавлено
					flagExtended = 1;
					break;
				}
				k = k->nextNode;
			}
		}

		//если варианты не отработали - завершаем дописывание, возвращаем фразу
		if (!flagExtended)
		{
			return phraseBeginning;
		}

		//даже если в сначала бегининг фразы состоял из одного слова, 
		// раз ретурн не отработал, теперь хотя бы два есть 
		phraseBeginning_wordsCounter = 2;
	}
	return phraseBeginning;
}


