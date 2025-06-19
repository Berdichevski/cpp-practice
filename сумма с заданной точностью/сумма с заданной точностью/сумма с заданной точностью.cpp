#include <iostream>
using namespace std;

int fact(int m)
{
	int factorial = 1;
	while (m)
	{
		factorial *= m;
		m--;
	}
	return factorial;
}

int main()
{
		double a, e, x, sum;
		cout << "Insert e and, then, x" << endl;
		cin >> e >> x;
		sum = 0;
		a = x;
		int numerator = x;
		double sign = 1;
		double devider_1 = 1;
		double devider_2 = 1;
		for (a; fabs(a) > e; a = sign * numerator / devider_1 / fact(devider_2))
		{
			sum += a;
			sign *= (-1);
			numerator *= x * x;
			devider_1 *= 3;
			devider_2 += 2;
		}
		cout << sum << endl;
		return 0;
}

