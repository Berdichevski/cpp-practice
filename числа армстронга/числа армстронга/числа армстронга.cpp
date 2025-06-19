#include <iostream>
#include <string>

using namespace std;

int main()
{
	int numbersamount, numeric, memnumeric, sumarmstrong;
	cin >> numeric;
	memnumeric = numeric;
	numbersamount = to_string(numeric).length();
	sumarmstrong = 0;
	while (numeric)
	{
		sumarmstrong += pow(numeric % 10, numbersamount);
		numeric = static_cast<int>(numeric / 10);
	}
	if (sumarmstrong == memnumeric)
		cout << "The number is an Armstrong's number";
	else
		cout << "The number is NOT an Armstrong's number";
}
	