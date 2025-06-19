#include <iostream>

using namespace std;

int main()
{
	int m, n, k;
	cin >> n >> m >> k;
	int ans = (n * m / k) - (n % k != 0 && m % k != 0 && n * m % k == 0);
	cout << ans << endl;
}