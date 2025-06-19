#include <iostream>;
#include <string>;
#include <algorithm>;
using namespace std;

int main()
{
	int lenarr, lenarr1;
	int arr[100] = {};
	int arr1[100] = {};

	cout << "Insert the degree of the first polynomial." << endl;
	cin >> lenarr;

	lenarr++;

	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next factor." << endl;
		cin >> arr[i];
	}

	cout << "Insert the degree of the second polynomial." << endl;
	cin >> lenarr1;

	lenarr1++;

	for (int i = 0; i < lenarr1; i++)
	{
		cout << "Insert the next factor." << endl;
		cin >> arr1[i];
	}

	cout << "Factors of the sum are ";
	for (int i = 0; i < max(lenarr, lenarr1); i++)
	{
		cout << arr[i] + arr1[i] << " ";
	}

	cout << endl << "Factors of the multiplication are ";

	for (int i = 0; i < lenarr + lenarr1 - 1; i++)
	{
		int sum = 0;
		for (int j = 0; j <= i; j++)
		{
			sum += arr[j] * arr1[i - j];
		}
		cout << sum << " ";
	}
}


