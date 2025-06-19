#include <iostream>
#include <cmath>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    double lm, rm, tm, bm, len, x, y;
    std::cout << "Insert coordinates of the point" << "\n";
    std::cin >> x >> y;
    std::cout << "Insert length of the side of the sqare" << "\n";
    std::cin >> len;
    lm = -(len / 2);
    rm = (len / 2);
    tm = (len / 2);
    bm = -(len / 2);
    if (((x == lm) || (x == rm)) && (bm <= y && y <= tm))
        std::cout << "The point is on the side of the square";
    else if (((y == tm) || (y == bm)) && (lm <= x && x <= rm))
        std::cout << "The point is on the side of the square";
    else if ((abs(x) < len / 2) && (abs(y) < len / 2))
        std::cout << "The point is inside the square";
    else
        std::cout << "The point is outside the square";
}