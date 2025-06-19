#include <iostream>
#include <string>
using namespace std;

int main()
{
	double matr[100][100];
	int n, m;
	cout << "Insert the size of the matrix" << endl;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Insert the next number of the matrix" << endl;
			cin >> matr[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	int maxInLine[100];
	int minInColumn[100];

	for (int i = 0; i < n; i++)
	{
		maxInLine[i] = INT_MIN;
	}

	for (int i = 0; i < m; i++)
	{
		minInColumn[i] = INT_MAX;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
//			cout << matr[i][j] << " ";

			if (matr[i][j] > maxInLine[i])
			{
				maxInLine[i] = matr[i][j];
			}
			if (matr[i][j] < minInColumn[j])
			{
				minInColumn[j] = matr[i][j];
			}
		}
	}

/*	cout << endl << endl;

	for (int i = 0; i < max(m, n); i++)
	{
		cout << maxInLine[i] << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < max(m, n); i++)
	{
		cout << minInColumn[i] << " ";
	}

	cout << endl << endl;*/
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((matr[i][j] == minInColumn[j]) && (matr[i][j] == maxInLine[i]))
			{
				cout << i << " " << j;
			}
		}
	}
}



	