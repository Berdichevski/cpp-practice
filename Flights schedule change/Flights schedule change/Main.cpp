#include <iostream>
#include <climits>
#include <fstream>

using namespace std;

int makeGraphClosed(int** graph, bool** added, int size, int a)
{
    int CostOfaddedEdges = 0;

    for (int i = 0; i < size; ++i) 
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (!graph[i][j] && i!=j) 
            {
                graph[i][j] = 1;
                added[i][j] = true;
                graph[j][i] = 1;
                added[j][i] = true;
                CostOfaddedEdges +=a;
            }
        }
    }
    return CostOfaddedEdges;
}


void removeExtraEdges(int** adjacencyMatrix, bool** additionalEdges, int n, int d, int a) 
{
    int** shortestPaths = new int* [n];

    for (int i = 0; i < n; ++i) 
    {
        shortestPaths[i] = new int[n]();
    }

    for (int i = 0; i < n; ++i) 
    {
        int* dist = new int[n];
        bool* visited = new bool[n]();

        for (int j = 0; j < n; ++j) 
        {
            dist[j] = INT_MAX;
        }

        dist[i] = 0;

        for (int count = 0; count < n - 1; ++count) 
        {
            int minDist = INT_MAX;
            int u = -1;

            for (int v = 0; v < n; ++v) {
                if (!visited[v] && dist[v] < minDist) 
                {
                    minDist = dist[v];
                    u = v;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; ++v) 
            {
                if (!visited[v] && adjacencyMatrix[u][v] && 
                    dist[u] != INT_MAX && dist[u] + adjacencyMatrix[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + adjacencyMatrix[u][v];
                }
            }
        }

        for (int j = 0; j < n; ++j) 
        {
            if (i != j && dist[j] != INT_MAX) 
            {
                shortestPaths[i][j] = dist[j];
            }
        }

        delete[] dist;
        delete[] visited;
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (additionalEdges[i][j] && additionalEdges[i][j] > shortestPaths[i][j]) 
            {
                adjacencyMatrix[i][j] = 0;
                adjacencyMatrix[j][i] = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        delete[] shortestPaths[i];
    }
    delete[] shortestPaths;
}

int main() 
{
    ifstream file("graph.txt");
    if (!file.is_open()) 
    {
        cout << "Unable to open file." << endl;
        return 1;
    }

    int size, d, a;
    file >> size;
    file >> d;
    file >> a;

    int** graph = new int* [size];
    for (int i = 0; i < size; ++i) 
    {
        graph[i] = new int[size]();
    }

    // Заполнение матрицы смежности из файла
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            file >> graph[i][j];
        }
    }

    file.close();

    bool** added = new bool* [size];
    for (int i = 0; i < size; ++i)
    {
        added[i] = new bool[size] {false};
    }

    int addedEdges = makeGraphClosed(graph, added, size, a);

    int start = 0;
    int* shortest_distances = new int[size];
    int* parents = new int[size];

    removeExtraEdges(graph, added, size, d, a);

    //int deletedEdges = removeExtraEdges(graph, added, size, d, a);

    //cout << addedEdges + deletedEdges << "$ - " << deletedEdges / d << endl;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    //// Освобождение памяти
    //for (int i = 0; i < size; ++i) {
    //    delete[] graph[i];
    //}

    return 0;
}

//int main() {
//    int adjacencyMatrix[MAX_N][MAX_N] = {
//        {0, 1, 1, 0},
//        {1, 0, 0, 1},
//        {1, 0, 0, 1},
//        {0, 1, 1, 0}
//    };
//
//    int additionalEdges[MAX_N][MAX_N] = {
//        {0, 1, 4, 0},
//        {1, 0, 0, 2},
//        {4, 0, 0, 1},
//        {0, 2, 1, 0}
//    };
//
//    int n = 4; // Размер матрицы
//
//    removeExtraEdges(adjacencyMatrix, additionalEdges, n);
//
//    // Вывод обновленной матрицы смежности
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            std::cout << adjacencyMatrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}