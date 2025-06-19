//Надо ли прибавлять в делители САМО ЧИСЛО?




#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    int a, b, sumdividersa, sumdividersb;
    std::cout << "Insert two numbers" << "\n";
    std::cin >> a >> b;
    sumdividersa = 0;
    sumdividersb = 0;
    if ((a != 0) && (b != 0))
    {
        for (int i = 1; i < a; i++)
        {
            if (a % i == 0)
                sumdividersa += i;
        }
        for (int i = 1; i < b; i++)
        {
            if (b % i == 0)
                sumdividersb += i;
        }

 //       std::cout << sumdividersa << "\n";
 //       std::cout << sumdividersb << "\n";

        if ((sumdividersa == b) && (sumdividersb == a))
            std::cout << "Numbers are friendly";
        else
            std::cout << "Numbers aren't friendly";
    }
    else
        std::cout << "Undefined";
}