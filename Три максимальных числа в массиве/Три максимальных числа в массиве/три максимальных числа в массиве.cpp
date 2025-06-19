#include <iostream>

using namespace std;

int main()
{
	int lenarr = 0;
	int arr[100];
	int maximum_1, maximum_2, maximum_3;
	maximum_1 = maximum_2 = maximum_3 = -100;

	cout << "Insert the length of the array." << endl;
	cin >> lenarr;
	if (lenarr > 100)
	{
		cout << "Error. The array is too big." << endl;
		return 0;
	}

	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next number in the array." << endl;
		cin >> arr[i];
	}


	for (int i = 0; i < lenarr; i++)
	{
		if (arr[i] > maximum_1) 
			maximum_1 = arr[i];
	}
	for (int i = 0; i < lenarr; i++)
	{
		if ((arr[i] > maximum_2) && (arr[i] != maximum_1))
			maximum_2 = arr[i];
	}
	for (int i = 0; i < lenarr; i++)
	{
		if ((arr[i] > maximum_3) && (arr[i] != maximum_1) && (arr[i] != maximum_2))
			maximum_3 = arr[i];
	}

	cout << "Three maximum elements = {" << maximum_1 << ", " << maximum_2 << ", " << maximum_3 << "}";
}


