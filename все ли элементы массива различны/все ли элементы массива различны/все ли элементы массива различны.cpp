#include <iostream>

using namespace std;

int main() {
	int lenarr, a = 0;
	int arr[100];

	cout << "Insert the length of the array." << endl;
	cin >> lenarr;
	if (lenarr > 100)
	{
		cout << "Error. The array is too big." << endl;
		return 0;
	}

	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next number in the first array." << endl;
		cin >> arr[i];
	}

	for (int i = 1; i < lenarr-1; i++) 
	{
		for (int j = i+1; j < lenarr; j++)
		{
			if (arr[i] == arr[j]) 
			{
				a += 1;
			}
		}
	}


	if (a) {
		cout << "NOT each number in the array is different from another" << endl;
	}
	else {
		cout << "Each number in the array is different from another" << endl;
	}

	return 0;
}