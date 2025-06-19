#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() {

	//запрос кол-ва человек
	int n;
	cout << "Insert number of people: ";
	cin >> n;

	//создание списка номеров людей
	List listOfNumbers;
	for (int i = 0; i < n; i++)
	{
		listOfNumbers.Append(i);
	}

	//запрос остальных вводных
	int k;//стартовая позиция
	cout << "Insert starting number: ";
	cin >> k;

	int m;//кол-во слов в считалочке
	cout << "Insert number of words in counting rhyme: ";
	cin >> m;

	Node* Node = listOfNumbers.getHead();

	//переход к стартовой позиции
	for (int i = 0; i < k; i++)
	{
		Node = Node->getNext();
	}

	/*cout << Node->getNumber() << endl;*/

	//идем по кругу
	while (Node->getNext() != Node)
	{
		//переходим до предыдущего перед выбывающим
		for (int i = 0; i < m - 2; i++)
		{
			if (Node->getNext() != Node)
			{
				Node = Node->getNext();
			}
			else
			{
				cout << Node->getNumber() << " - left";
				return 0;
			}
		}
		//удаляем узел выбывающего
		if (Node->getNext() == listOfNumbers.getHead())
		{
			listOfNumbers.setHead(listOfNumbers.getHead()->getNext());
		}
		Node->deleteNextNode();
		//переходим к следующему
		if (Node->getNext() != Node)
		{
			Node = Node->getNext();
		}
		else
		{
			cout << Node->getNumber() << " - left";
			return 0;
		}
	}
	cout << Node->getNumber() << " - left";
	return 0;
}





