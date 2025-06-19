#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[100];
	int lenarr;
	cout << "Insert the length of the array" << endl;
	cin >> lenarr;
	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next number" << endl;
		cin >> arr[i];
	}

	for (int i = 0; i < lenarr; i++)
	{
		int counter = 0;
		for (int j = 0; j < lenarr; j++)
		{
			if (arr[j] == arr[i])
			{
				counter++;
			}
			if (counter > lenarr / 2)
			{
				cout << endl << arr[i];
				return 0;
			}
		}
	}
}