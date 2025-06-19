#include <iostream>
using namespace std;

int main()
{
	int matr1[100][100], matr2[100][100];
	int m, n;
	cout << "Insert the size of the matrix" << endl;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Insert the next number of the first matrix" << endl;
			cin >> matr1[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Insert the next number of the second matrix" << endl;
			cin >> matr2[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr1[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr2[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "Sum = " << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matr1[i][j] = matr1[i][j] + matr2[i][j];
			cout << matr1[i][j] << " ";
		}
		cout << endl;
	}

}




