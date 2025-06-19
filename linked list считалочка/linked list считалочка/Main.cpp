#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() {

	//������ ���-�� �������
	int n;
	cout << "Insert number of people: ";
	cin >> n;

	//�������� ������ ������� �����
	List listOfNumbers;
	for (int i = 0; i < n; i++)
	{
		listOfNumbers.Append(i);
	}

	//������ ��������� �������
	int k;//��������� �������
	cout << "Insert starting number: ";
	cin >> k;

	int m;//���-�� ���� � ����������
	cout << "Insert number of words in counting rhyme: ";
	cin >> m;

	Node* Node = listOfNumbers.getHead();

	//������� � ��������� �������
	for (int i = 0; i < k; i++)
	{
		Node = Node->getNext();
	}

	/*cout << Node->getNumber() << endl;*/

	//���� �� �����
	while (Node->getNext() != Node)
	{
		//��������� �� ����������� ����� ����������
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
		//������� ���� �����������
		if (Node->getNext() == listOfNumbers.getHead())
		{
			listOfNumbers.setHead(listOfNumbers.getHead()->getNext());
		}
		Node->deleteNextNode();
		//��������� � ����������
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





