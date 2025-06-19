#include <iostream>
#include <string>
using namespace std;

int main()
{
	double matr[100][100];
	int m, n;
	cout << "Insert the size of the matrix" << endl;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Insert the next number of the matrix" << endl;
			cin >> matr[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	int counter = 0;
	for (int i = 0; i < m; i++)
	{
		int j = 0;
		bool indicator = 1;
		while ((j < n) && indicator)
		{
			if (matr[i][j] != 0)
			{
				indicator *= 0;
			}
			j++;
		}
		if (indicator)
		{
			counter++;
		}
	}

	cout << counter;
}