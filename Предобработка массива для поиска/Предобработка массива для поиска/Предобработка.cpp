#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    //ввод массива
    int size;
    cin >> size;
    char* array = new char[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }

    //предобработка
    int counter = 0;

    unordered_set<char> uniqueArray;

    int* indexes = new int[size];

    for (int i = 0; i < size; i++)
    {
        if (uniqueArray.find(array[i]) == uniqueArray.end())
        {
            indexes[counter] = i;
            counter++;
        }
        uniqueArray.insert(array[i]);
    }

    //проверочный вывод массива алфавита
    for (char element : uniqueArray) 
    {
        cout << element << " ";
    }

    cout << endl;

    for (int i = 0; i < counter; i++)
    {
        cout << indexes[i] << " ";
    }

    cout << endl;

    //функция поиска
    char neededSymb;
    cout << "What symbol are we looking for?" << endl;
    cin >> neededSymb;
    bool flag = 1;
    counter = 0;
    for (char element : uniqueArray)
    {
        if (element == neededSymb)
        {
            flag = 0;
            cout << indexes[counter];
        }
        counter++;
    }
    if (flag)
    {
        cout << -1;
    }
}
    
