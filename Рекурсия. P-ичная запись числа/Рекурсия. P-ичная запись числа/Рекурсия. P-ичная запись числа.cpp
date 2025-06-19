#include <iostream>
#include <string>
using namespace std;

string moreThanNine(int number)
{
	switch(number)
	{
		case 10:
		{
			return "A";
		}
		case 11:
		{
			return "B";
		}
		case 12:
		{
			return "C";
		}
		case 13:
		{
			return "D";
		}
		case 14:
		{
			return "E";
		}
		case 15:
		{
			return "F";
		}
	}
}

string numberToBase(int num, int base)
{
	if (num < base)
	{
		if (num < 10)
		{
			return to_string(num);
		}
		else
		{
			return moreThanNine(num);
		}
	}
	else
	{
		return numberToBase(num / base, base) + numberToBase(num % base, base);
	}
}

int main() 
{
	int number, base;
	cin >> number >> base;

	cout << numberToBase(number, base);
}