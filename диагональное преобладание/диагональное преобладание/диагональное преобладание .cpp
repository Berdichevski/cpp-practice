#include <iostream>
#include <string>
using namespace std;

int main()
{
	double matr[100][100];
	int n;
	cout << "Insert the size of the matrix" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Insert the next number of the matrix" << endl;
			cin >> matr[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	bool indicator_strict = 0;
	bool indicator = 1;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;

		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				sum += abs(matr[i][j]);
			}
		}
		if (matr[i][i] > sum)
		{
			indicator_strict = 1;
		}
		else if (matr[i][i] < sum)
		{
			indicator *= 0;
		}
	}

	if (indicator_strict && indicator)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
}