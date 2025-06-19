#include <iostream>
#include <fstream>
using namespace std;
char graph[100][100];
char changes[100][100];
bool visited[100]{ false };
int totalCost = 0, n, d, a;


void dfs(int v, int p) 
{
    visited[v] = true;
    for (int i = 0; i < n; ++i) 
    {
        if (graph[v][i] == '1') 
        {
            if (!(visited[i])) 
            {
                dfs(i, v);
            }
            else if (i > v && i != p) 
            {
                changes[v][i] = changes[i][v] = 'd';
                graph[v][i] = graph[i][v] = '0';
                totalCost += d;
            }

        }
    }
}


int main() 
{
    ifstream fin("in.txt");
    if (fin.is_open()) 
    {
        fin >> n >> d >> a;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                fin >> graph[i][j];
                changes[i][j] = '0';
            }
        }
        fin.close();
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }

    cout << endl;

    dfs(0, 0);

    for (int i = 1; i < n; ++i) 
    {
        if (!visited[i]) 
        {
            dfs(i, i);
            changes[i][0] = 'a';
            changes[0][i] = 'a';
            graph[i][0] = '1';
            graph[0][i] = '1';

            totalCost += a;
        }
    }

    //changes

    cout << totalCost << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << changes[i][j];
        }
        cout << endl;
    }

    cout << endl;

    //result

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}
