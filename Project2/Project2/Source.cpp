#include <iostream>
#include <string>
using namespace std;

int findMax(int arr[], int size)
{
	if (size == 1)
	{
		return arr[0];
	}
	else
	{
		int elementMax = findMax(arr, size - 1);
		if (arr[size - 1] > elementMax)
		{
			return arr[size - 1];
		}
		else
		{
			return elementMax;
		}
	}
}

int main()
{
	int size;
	cin >> size;
	int arr[100];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	int maxElement = findMax(arr, size);
	cout << "Max element is: " << maxElement << endl;

	return 0;
}