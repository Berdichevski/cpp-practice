// с нудем в середине
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int numberside1, numberside2;
	cin >> numberside1;
	numberside2 = numberside1;
	while (numberside2)
	{
		cout << numberside1 << " " << numberside2 << "\n";
		if (numberside1 % 10 != static_cast<int> (numberside2 / pow(10, to_string(numberside2).length() - 1)))
		{
			cout << "Number is not polyndrome";
			return 0;
		}
		else
		{
			numberside1 = static_cast < int> ( numberside1 / 10 );
			numberside2 = numberside2 % static_cast<int> ( pow(10, to_string(numberside2).length() - 1) );
		}
	}
	cout << "Number is polyndrome!";
}