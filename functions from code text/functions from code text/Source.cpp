#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main() 
{
    ifstream input("input.txt"); 
    ofstream outputR("outputR.txt");
    ofstream output("output.txt");

    if (!((input.is_open()) && (outputR.is_open()) && (output.is_open())))
    {
        cout << "Files not open!" << endl;
    }

    string word;
    string funcName = "";
    regex pattern("[a-zA-Z_][a-zA-Z0-9_]*\\((.*)");
    while (input >> word)
    {
        if (regex_match(word, pattern))
        {
            bool flagRecursive = 0;
            funcName = "";
            int i = 0;
            while (word[i] != '(')
            {
                funcName += word[i];
                i++;
            }
            cout << funcName << endl;
            string regExString = funcName + "\\(.*";
            regex patternCur(regExString);
            int openedBrackets = 0;
            int closedBrackets = 0;
            while ((openedBrackets > closedBrackets) || (closedBrackets == 0))
            {
                input >> word;
                if (word == "{")
                {
                    openedBrackets++;
                }
                else if (word == "}")
                {
                    closedBrackets++;
                }
                else if (regex_match(word, patternCur))
                {
                    flagRecursive = 1;
                }
            }
            if ((flagRecursive) && (openedBrackets == closedBrackets))
            {
                outputR << funcName << endl;
            }
            else if (openedBrackets == closedBrackets)
            {
                output << funcName << endl;
            }
        }
    }

    input.close(); 
    return 0;
}