#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int startPointer = 0;
	int endPointer = sizeof(arr) / sizeof(arr[0]);
	int searchElement;
	cin >> searchElement;
	int midIndex;

	while (startPointer != endPointer)
	{
		midIndex = (endPointer + startPointer) / 2;

		if (arr[startPointer + midIndex] == searchElement)
		{
			cout << startPointer + midIndex;
			return 0;
		}

		else if (arr[startPointer + midIndex] > searchElement)
		{
			endPointer--;
		}

		else if (arr[startPointer + midIndex] < searchElement)
		{
			startPointer++;
		}
	}

	cout << -1;
}
