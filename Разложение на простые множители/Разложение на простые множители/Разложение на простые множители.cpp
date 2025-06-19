#include <iostream>

int main()
{
    int n, k, k0, kmax;
    std::cin >> n;
    k0 = 0;
    kmax = 0;
    for (int i = 2; i * i <= n; i++)
    {
        k = 0;
        while (n % i == 0)
        {
            std::cout << i << "\n";
            n /= i;
            k += 1;
        }
        if ((k > k0) && (k != 1))
        {
            kmax = i;
            k0 = k;
        }
    }
    if (n > 1)
        std::cout << n << "\n";
    if (kmax!=0)
        std::cout << kmax;
}