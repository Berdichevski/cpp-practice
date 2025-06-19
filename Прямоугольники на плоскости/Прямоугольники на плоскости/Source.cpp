
#include <iostream>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    double lm1, rm1, tm1, bm1, lm2, rm2, tm2, bm2, widol, hiol, Sol;
    std::cout << "Please type in both coordinates of left top point of the first rectangle and right bottom point of the first rectangle)" << "\n";
    std::cin >> lm1 >> tm1 >> rm1 >> bm1;
    std::cout << "Please type in both coordinates of left top point of the second rectangle and right bottom point of the second rectangle))" << "\n";
    std::cin >> lm2 >> tm2 >> rm2 >> bm2;
    if (not (((lm1 > rm2) || (lm2 > rm1)) && ((bm1 > tm2) || (bm2 > tm1))))
    {
        widol = max(0, min(rm1, rm2) - max(lm1, lm2));
        hiol = max(0, min(tm1, tm2) - max(bm1, bm2));
    }
    Sol = widol * hiol;
    if (Sol == 0)
    {
        std::cout << "The rectangles do not overlap.";
    }
    else
    {
        std::cout << "The rectangles overlap. The overlap area is " << Sol;
    }
}