#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'";
string marks = ".!?;:()";

bool includes(const string& str, char ch) 
{
	for (char c : str) {
		if (c == ch) {
			return true;
		}
	}
	return false;
}

int main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	if (!fin.is_open() || !fout.is_open())
	{
		cout << "Error opening files." << endl;
		return 0;
	}

	Text text = Text();
	Sentence tempSentence = Sentence();
	string tempWord = "";
	while (fin)
	{
		char tempChar;
		fin.get(tempChar);
		//cout << tempChar << endl;
		tempChar = tolower(tempChar);

		if (includes(alphabet, tempChar))
		{
			tempWord += tempChar;
		}
		else if (tempChar == ',')
		{
			continue;
		}
		else if (!includes(marks, tempChar))
		{
			tempSentence.Append(tempWord);
			tempWord = "";
		}
		else
		{
			tempSentence.Append(tempWord);
			tempWord = "";
			text.CopyAndAppend(tempSentence);
			tempSentence.Clean();
		}
	}

	
	Sentence* j = text.getHead();
	Word* i = j->getHead();
	
	while (j != nullptr) {
		while (i != nullptr) {
			fout << i->getWord() << " ";
			i = i->getNext();
		}
		fout << endl;
		j = j->getNext();
		if (j != nullptr)
		{
			i = j->getHead();
		}
	}
}