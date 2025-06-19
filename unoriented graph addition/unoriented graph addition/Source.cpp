#include <iostream>
// �� ������� ��������� � ������� �������������
int cEg(int n, int** g) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; j++) { // j <= i �.�. ����������������� ����
            ans += (g[i][j] != 0);
        }
    }
    return ans;
}

int** toInc(int** g, int n, int& k) {
    int m = cEg(n, g); // �������, ��������� ���������� ����
    int** inc = new int* [n];
    k = m;
    for (int i = 0; i < n; ++i) {
        inc[i] = new int[m] {0};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; j++) {
            if (g[i][j]) {
                inc[i][m - 1] = 1; // �� ����� ������ k = 0 --> [i][k] � k++
                inc[j][m - 1] = 1;
                m--; // �� ������ ������� ������ ������ ������ ��� ������
            }
        }
    }
    return inc;
}

// �� ������� ��������� � ������ ������� ����
struct mem {
    int* e; // ������ ������ �������
    int s; // size
};
mem* toSm(int** g, int n) { // ���������� ������ ��������
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
                m[i].e[allo - 1] = j; // ������ ���������� ������� � ����� �������
                allo--;
            }
        }
    }
    return m;
}


// ���� ����� ������� �������
int main() {
    std::cout << "Hello World!\n";
    return 0;
}