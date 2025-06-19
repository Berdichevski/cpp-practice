#include <iostream>

using namespace std;

int BinarySearch(int* array, int startPointer, int endPointer, int searchElement)
{
//	cout << startPointer << " " << endPointer << "  ";
	if (startPointer >= endPointer)
	{
		return -1;
	}

	int midIndex = (endPointer + startPointer) / 2;

	if (array[startPointer + midIndex] == searchElement)
	{
		return startPointer + midIndex;
	}

	else if (array[startPointer + midIndex] > searchElement)
	{
		return BinarySearch(array, startPointer, endPointer - 1, searchElement);
	}

	else if (array[startPointer + midIndex] < searchElement)
	{
		return BinarySearch(array, startPointer + 1, endPointer, searchElement);
	}
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int startPointer = 0;
	int endPointer = sizeof(arr) / sizeof(arr[0]);
	int searchElement;
	cin >> searchElement;
	cout << BinarySearch(arr, startPointer, endPointer, searchElement);
}
