#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int adj[1000][1000];
bool visited[1000];

int bfs(int start, int end, int n, int parent[]) 
{
    Queue q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int node = q.pop();

        if (node == end) 
        {
            return node;
        }

        for (int neighbor = 1; neighbor <= n; ++neighbor) 
        {
            if (adj[node][neighbor] && !visited[neighbor]) 
            {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    return -1; // ѕуть не найден
}

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Error" << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int start, end;
    cin >> start >> end;

    fin.close();

    int parent[1000] = { 0 };
    int result = bfs(start, end, n, parent);

    if (result != -1) {
        cout << "The shortest way between " << start << " and " << end << " : ";
        while (end != start) {
            cout << end << " ";
            end = parent[end];
        }
        cout << start << endl;
    }
    else {
        cout << "Way not found." << endl;
    }

    return 0;
}