#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!((input.is_open()) && (output.is_open())))
    {
        cout << "Files not open!" << endl;
    }

    char ch;
    int openedBrackets = 0, closedBrackets = 0;

    ListMessages list;
    string mes = "";
    bool flagWrite = 1;
    while (input.get(ch)) 
    { 
        if ((ch == '{') || (ch == '[') || (ch == '('))
        {
            openedBrackets++;
            mes = "";
            flagWrite = 1;
        }
        else if ((ch == '}') || (ch == ')') || (ch == ']'))
        {
            closedBrackets++;
            flagWrite = 0;
        }
        else
        {
            if (flagWrite)
            {
                mes += ch;
            }
        }

//        cout << ch << endl;
//        cout << " opened " << openedBrackets << " closed " << closedBrackets << endl;
         
        if ((openedBrackets == closedBrackets) && (closedBrackets != 0))
        {
            list.append(mes, openedBrackets);
            openedBrackets = 0;
            closedBrackets = 0;
        }
    }

    int nLevMax = 0;
    message* m = list.getHead();
    while (m != nullptr)
    {
        if (m->nLevel > nLevMax)
        {
            nLevMax = m->nLevel;
        }
        m = m->next;
    }

    m = list.getHead();
    while (m != nullptr)
    {
        if (m->nLevel == nLevMax)
        {
            output << m->data << endl;
            break;
        }
        m = m->next;
    }

    input.close();
    return 0;
}