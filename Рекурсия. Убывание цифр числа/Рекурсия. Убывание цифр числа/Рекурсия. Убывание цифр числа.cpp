#include <iostream>
#include <string>
using namespace std;

bool digitReduction(string num)
{
	if (num.length() <= 1)
	{
		return true;
	}
	else
	{
		if (num[num.length() - 1] < num[num.length() - 2])
		{
			return true * digitReduction(num.substr(0, num.length() - 1));
		}
		else
		{
			return false;
		}
	}
}

int main() {
	string number;
	cin >> number;
	
	if (digitReduction(number))
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

	return 0;
}           