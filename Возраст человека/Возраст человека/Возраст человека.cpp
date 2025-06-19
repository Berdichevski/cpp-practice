#include <iostream>

int main()
{
    int a, b;
    std::cin >> a;
    if (11 <= a % 100 && a % 100 <= 15)
    {
        std::cout << a << " " << "let";
    }
    else
    {
        b = a % 10;
        if (b == 1)
            std::cout << a << " " << "god";
        if (b == 2 || b == 3 || b == 4)
            std::cout << a << " " << "goda";
        if (b == 5 || b == 6 || b == 7 || b == 8 || b == 9 || b == 0)
            std::cout << a << " " << "let";
    }
}