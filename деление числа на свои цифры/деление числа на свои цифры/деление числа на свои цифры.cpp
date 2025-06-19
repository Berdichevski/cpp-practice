#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number, memnumber;
	cin >> number;
	memnumber = number;
	while (number)
	{
		if (number % 10 != 0)
		{
			if (memnumber % (number % 10) == 0)
			{
				cout << "Divides";
				return 0;
			}
		}
			number /= 10;
	}
	cout << "Does not divide";
}