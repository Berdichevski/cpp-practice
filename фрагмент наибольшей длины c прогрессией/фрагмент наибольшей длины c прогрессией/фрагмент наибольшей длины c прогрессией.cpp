#include <iostream>

using namespace std;

int main()
{
	int lenarr = 0;
	int arr[100];
	int ans[100];
	int maximum_1, maximum_2, maximum_3;
	maximum_1 = maximum_2 = maximum_3 = -100;
	int len = 2;
	int lenmax = -1;

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

	arr[lenarr] = arr[lenarr - 1] + (arr[lenarr - 2] - arr[lenarr - 1]) + 1;

	for (int i = 1; i < lenarr; i++)
	{
		if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i]))
		{
			len += 1;
		}
		else
		{
			if (len > lenmax)
			{
				lenmax = len;
				int j;
				int ansindex = 0;
				for (j = i + 1 - len; j < i + 1; j++)
				{
					ans[ansindex] = arr[j];
					ansindex++;
				}
			}
			len = 2;
		}
	}

	if (lenmax == 2)
	{
		cout << "There isn't any algebraic progression in the array";
		return 0;
	}

	cout << "The biggest fragment is ";
	for (int i = 0; i < lenmax; i++)
	{
		cout << ans[i] << " ";
	}

}