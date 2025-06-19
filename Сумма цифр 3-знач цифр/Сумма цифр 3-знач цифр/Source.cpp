#include <iostream>

int main()
{
	int n, ans;
	std::cin >> n;
	ans = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				if (i + j + k == n)
				{ 
					//std::cout << i << j << k <<"\n";
					ans++;
				}
	std::cout << ans;
}