#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_WORDS = 100;  // Максимальное количество слов

int main() {
    string reservedWords[MAX_WORDS]; // Массив для хранения зарезервированных слов
    int wordCount[MAX_WORDS] = { 0 }; // Массив для хранения количества слов
    int numWords = 0; // Количество слов в массиве

    ifstream reservedFile("reservedwords.txt"); // Открываем файл с зарезервированными словами для чтения
    if (!reservedFile) 
    {
        cout << "Couldn't open reservedwords.txt\n";
        return 1;
    }

    // Считываем зарезервированные слова из файла и инициализируем их количество в wordCount нулем
    string reservedWord;
    while (reservedFile >> reservedWord) 
    {
        reservedWords[numWords] = reservedWord;
        numWords++;
    }
    reservedFile.close();

    ifstream textFile("text.txt"); // Открываем файл с текстом для чтения
    if (!textFile) {
        cout << "Couldn't open text.txt\n";
        return 1;
    }
    // Считываем слова из файла с текстом и увеличиваем их количество в wordCount
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

    // Сортируем wordCount в порядке убывания
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

    // Выводим отсортированные слова и их количество
    for (int i = 0; i < numWords; i++) 
    {
        cout << reservedWords[i] << ": " << wordCount[i] << endl;
    }

    return 0;
}