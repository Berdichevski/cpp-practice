#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	int lenarr;
	int arr[100];
	int arr1[100];

	cout << "Insert the length of the array." << endl;
	cin >> lenarr;

	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next number in the first array." << endl;
		cin >> arr[i];
	}

	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next number in the second array." << endl;
		cin >> arr1[i];
	}

	int i = 0, j = lenarr - 1;
	while (i<lenarr)
	{
		//cout << arr[i] << " " << arr1[j] << endl;
		string a = to_string(arr[i]);
		string b = to_string(arr1[j]);
		int k = 0, w = size(b) - 1;
		while ((k < size(a)) && (w >= 0))
		{
			//cout << "------" << a[k] << " " << b[w] << endl;
			if (a[k] != b[w])
			{
				cout << "False";
				return 0;
			}
			else
			{
				k++;
				w--;
			}
		}
		i++;
		j--;
	}
	cout << "True";
	return 0;
}