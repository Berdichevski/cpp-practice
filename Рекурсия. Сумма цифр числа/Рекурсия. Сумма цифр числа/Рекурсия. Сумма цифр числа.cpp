#include <iostream>
#include <string>
using namespace std;

int digitSum(int num)
{
	if (num < 10)
	{
		return num;
	}
	else
	{
		int lastDigit = num % 10;
		int remainingDigits = num / 10;
		return lastDigit + digitSum(remainingDigits);
	}
}

int main() {
	int number;
	cin >> number;
	int sum = digitSum(number);

	std::cout << "Sum of digits " << number << " is " << sum;
	return 0;
}