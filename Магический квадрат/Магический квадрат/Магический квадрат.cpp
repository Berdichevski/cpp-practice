#include <iostream>
#include <fstream>

using namespace std;

// создаем магический квадрат

int createMatrix (int n)
{
    int magic_square[11][11] = {};
    int number = 1;
    int i = 0, j = n / 2;
    int pre_i, pre_j;

    if (n % 2 == 0) {
        return 0;
    }

    magic_square[i][j] = number++;

    while (number <= n * n)
    {
        pre_i = i;
        pre_j = j;

        i = i - 1; j = j + 1;

        if (j > n-1)
        {
            j = 0;
        }

        if (i < 0)
        {
            i = n-1;
        }

        if (magic_square[i][j] != 0)
        {
            i = pre_i + 1;
            j = pre_j;
        }

        magic_square[i][j] = number++;
    }

    std::ofstream file("magic_square.txt", ios::app);
    if (file.is_open()) 
    {
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                file << magic_square[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        file.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
    return 0;
}


int main()
{

    for (int n = 1; n < 12; n++)
    {
        createMatrix(n);
    }
}
        