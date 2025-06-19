#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
using namespace std;

int main() 
{

    //���������� ����������������� ����
    List reservedWords; 
    ifstream fin("inputReservedWords.txt");

    if (!fin.is_open())
    {
        cout << "Reserved words file not open!" << endl;
        return 0;
    }

    string word;
    while (fin >> word)
    {
        reservedWords.Append(word); 
    }

    fin.close();

    //������� ���� �� ������
    ifstream fin2("inputText.txt");

    if (!fin2.is_open())
    {
        cout << "Text file not open!" << endl;
        return 0;
    }

    while (fin2 >> word) 
    {
        reservedWords.checkAndAdd(word);
    }
    fin2.close();

    //���������� ������ ����������������� ����
    reservedWords.Sort();

    //����� ������ ����������������� ����
    ofstream fout("output.txt");

    if (!fout.is_open()) {
        cout << "Output file not open!" << endl;
        return 0;
    }

    Node* i = reservedWords.getHead();

    while (i != nullptr)
    {
        fout << i->getWord() << " - " << i->getInclusions() << endl;
        i = i->getNext();
    }

    fout.close(); 
}