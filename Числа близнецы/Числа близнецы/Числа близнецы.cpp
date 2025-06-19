#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    int a, b;
    std::cout << "Insert two numbers" << "\n";
    std::cin >> a >> b;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            std::cout << "Numbers aren't twins";
            return 0;
        }
    }
    for (int i = 2; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            std::cout << "Numbers aren't twins";
            return 0;
        }
    }
    if (abs(a - b) == 2)
        std::cout << "Numbers are twins";
    else
        std::cout << "Numbers aren't twins";
}
