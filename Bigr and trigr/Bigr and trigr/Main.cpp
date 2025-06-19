#include <iostream>
#include <fstream>
#include <cctype>
#include "Header.h"
#include <string>
using namespace std;


int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!(fout.is_open() && fin.is_open()))
    {
        cout << "Error!";
    }

    string sent = "", q = ".!?;:()", in, sum;
    while (fin)
    {
        getline(fin, sum);
        in = in + sum + ' ';
    }
    int size = in.size(), pointer = 0;
    bool f = 0, flag = 0;
    ListSentences list;
    while (pointer < size) {
        flag = 0;
        char s = tolower(in[pointer]);
        for (int i = 0; i < 8 && f; i++)
            if (s == q[i])
                flag = 1;
        if (flag && f && sent.size() > 1) {
            f = 0;
            sent += s;
            list.append(sent);
            sent = "";
            pointer++;
        }
        else {
            if (!flag) {
                sent += s;
                f = 1;
            }
        }
        pointer++;
    }

    ListGramms bigramms, trigramms;

    for (sentence* i = list.getHead(); i != nullptr; i = i->next) 
    {
        for (word* j = i->data.getHead(); j->next != nullptr; j = j->next) 
        {
            string gramma = j->data;
            bigramms.append(gramma, j->next->data);
        }
    }

    for (sentence* i = list.getHead(); i != nullptr; i = i->next) 
    {
        for (word* j = i->data.getHead(); j->next->next != nullptr; j = j->next) 
        {
            string gramma = j->data + ' ' + j->next->data;
            trigramms.append(gramma, j->next->next->data);
        }
    }

    for (gramm* i = bigramms.getHead(); i != nullptr && i->next != nullptr; i = i->next) 
    {
        for (gramm* j = i->next; j != nullptr; j = j->next) 
        {
            bool f = 1;
            if (i->data == j->data) 
            {
                for (int q = 0; q < i->n; q++) 
                {
                    if (i->post[q] == j->post[0]) 
                    {
                        i->freq[q]++;
                        f = 0;
                        bigramms.pop(j, bigramms.getHead());
                    }
                }
                if (f) 
                {
                    i->add(j->post[0]);
                    bigramms.pop(j, bigramms.getHead());
                }
            }
        }
    }

    for (gramm* i = trigramms.getHead(); i != nullptr && i->next != nullptr; i = i->next) 
    {
        for (gramm* j = i->next; j != nullptr; j = j->next) 
        {
            bool f = 1;
            if (i->data == j->data) 
            {
                for (int q = 0; q < i->n; q++) 
                {
                    if (i->post[q] == j->post[0]) 
                    {
                        i->freq[q]++;
                        f = 0;
                        trigramms.pop(j, trigramms.getHead());
                    }
                }
                if (f) {
                    i->add(j->post[0]);
                    trigramms.pop(j, trigramms.getHead());
                }
            }
        }
    }

    bigramms.sort();
    trigramms.sort();
    
    NextWords nextwords;

    for (gramm* i = bigramms.getHead(); i != nullptr; i = i->next) 
    {
        fout << i->data << ' ' << i->post[0] << endl;
        nextwords.append(i->data, i->post[0]);
    }

    fout << endl;

    for (gramm* i = trigramms.getHead(); i != nullptr; i = i->next) 
    {
        fout << i->data << ' ' << i->post[0] << endl;
        nextwords.append(i->data, i->post[0]);
    }

    fin.close();
    fout.close();

    //-----------------------------------------------------------------

    string phraseBeginning;
    int wordsCounter;
    cout << "Input phraseBeginning and wordsCounter" << endl;
    getline(cin, phraseBeginning);
    cin >> wordsCounter;
    cout << nextwords.textExtension(phraseBeginning, wordsCounter);
}