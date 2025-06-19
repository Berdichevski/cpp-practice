#include <iostream>
using namespace std;

int main()
{
	int factorial = 1;
	int i = 1;
	for (; i <= 6;)
	{
		factorial *= i;
		++i;
	}
	cout << factorial << endl;
}