#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_WORDS = 100;  // ������������ ���������� ����

int main() {
    string reservedWords[MAX_WORDS]; // ������ ��� �������� ����������������� ����
    int wordCount[MAX_WORDS] = { 0 }; // ������ ��� �������� ���������� ����
    int numWords = 0; // ���������� ���� � �������

    ifstream reservedFile("reservedwords.txt"); // ��������� ���� � ������������������ ������� ��� ������
    if (!reservedFile) 
    {
        cout << "Couldn't open reservedwords.txt\n";
        return 1;
    }

    // ��������� ����������������� ����� �� ����� � �������������� �� ���������� � wordCount �����
    string reservedWord;
    while (reservedFile >> reservedWord) 
    {
        reservedWords[numWords] = reservedWord;
        numWords++;
    }
    reservedFile.close();

    ifstream textFile("text.txt"); // ��������� ���� � ������� ��� ������
    if (!textFile) {
        cout << "Couldn't open text.txt\n";
        return 1;
    }
    // ��������� ����� �� ����� � ������� � ����������� �� ���������� � wordCount
    string word;
    while (textFile >> word) 
    {
        for (int i = 0; i < numWords; i++) 
        {
            if (word == reservedWords[i]) 
            {
                wordCount[i]++;
                break;
            }
        }
    }
    textFile.close();

    // ��������� wordCount � ������� ��������
    for (int i = 0; i < numWords - 1; i++) 
    {
        for (int j = i + 1; j < numWords; j++) 
        {
            if (wordCount[i] < wordCount[j]) 
            {
                swap(wordCount[i], wordCount[j]);
                swap(reservedWords[i], reservedWords[j]);
            }
        }
    }

    // ������� ��������������� ����� � �� ����������
    for (int i = 0; i < numWords; i++) 
    {
        cout << reservedWords[i] << ": " << wordCount[i] << endl;
    }

    return 0;
}