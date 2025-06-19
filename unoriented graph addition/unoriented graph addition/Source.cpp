#include <iostream>
// от матрицы смежности к матрице инцидентности
int cEg(int n, int** g) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; j++) { // j <= i т.к. неориентированный граф
            ans += (g[i][j] != 0);
        }
    }
    return ans;
}

int** toInc(int** g, int n, int& k) {
    int m = cEg(n, g); // функция, считаюзая количество рёбер
    int** inc = new int* [n];
    k = m;
    for (int i = 0; i < n; ++i) {
        inc[i] = new int[m] {0};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; j++) {
            if (g[i][j]) {
                inc[i][m - 1] = 1; // мы могли писать k = 0 --> [i][k] и k++
                inc[j][m - 1] = 1;
                m--; // мы строим матрицу справа налево потому что Кирилл
            }
        }
    }
    return inc;
}

// от матрицы смежности к списку смежных рёбер
struct mem {
    int* e; // массив вершин смежных
    int s; // size
};
mem* toSm(int** g, int n) { // возвращаем массив структур
    mem* m = new mem[n];
    for (int i = 0; i < n; i++) {
        int allo = 0;
        for (int j = 0; i < n; j++) {
            allo += (g[i][j] != 0);
        }
        m[i].s = allo;
        m[i].e = new int[allo];

        for (int j = 0; j < n; j++) {
            if (g[i][j]) {
                m[i].e[allo - 1] = j; // просто закидываем неважно в каком порядке
                allo--;
            }
        }
    }
    return m;
}


// граф задан списком списком
int main() {
    std::cout << "Hello World!\n";
    return 0;
}