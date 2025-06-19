#include <iostream>
#include <fstream>
#include "Header.h"
#include <string>
using namespace std;

int main() 
{
    ifstream fin("input.txt");

    if (!fin.is_open()) 
    {
        cout << "Failed to open the file." << endl;
        return 0;
    }

    string text;
    string line;

    while (getline(fin, line)) 
    {
        text += line + "\n";
    }

    fin.close();

    Stack stack(text.size());

    for (int i = 0; i < text.size(); i++)
    {
        char c = text[i];
        if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            if (stack.isEmpty())
            {
                cout << "Wrong positioning of brackets!";
                return 0;
            }
            stack.pop();
        }
    }

    if (stack.isEmpty())
    {
        cout << "Right positioning of brackets!)";
    }
    else
    {
        cout << "Wrong positioning of brackets!";
    }
    return 0;
}