#include <iostream>
#include <math.h>

int main()
{
    int x, r;
    std::cin >> x >> r;
    if (r <= x / 2)
        std::cout << "Eatten area = " << 3.14 * r * r;
    else
    {
        if (r <= x * sqrt(2) / 2)
            std::cout << "Eatten area = " << (3.14 * r * r) - 4 * ((r * r / 2) (3.14 * 90 / 180 - 1));
        else
            std::cout << "Eatten area = " << x * x;
    }
}