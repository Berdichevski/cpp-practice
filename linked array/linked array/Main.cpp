#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	if (!fin.is_open() || !fout.is_open()) 
	{
		std::cout << "Error opening files." << std::endl;
		return 0;
	}

	List listPositive;
	List listNegative;
	int zeroCounter = 0;
	while (fin)
	{
		int number;
		fin >> number;
		if (number > 0)
		{
			listPositive.Append(number);
		}
		else if (number < 0)
		{
			listNegative.Append(number);
		}
		else
		{
			zeroCounter++;
		}
	}

	listNegative.reverseLinkedList();
	
	Node* i = listPositive.getHead();
	while (i != nullptr) {
		fout << i->getNumber() << " ";
		i = i->getNext();
	}
	fout << endl;

	i = listNegative.getHead();
	while (i != nullptr) {
		fout << i->getNumber() << " ";
		i = i->getNext();
	}
	fout << endl;


	fout << "Amount of zeros = " << zeroCounter;
}



