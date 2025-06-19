#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	n++;
	int matrix[100][100]{ 0 };
	matrix[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		matrix[i][0] = 1;
		matrix[i][i+1] = 1;
		for (int j = 1; j < i; j++)
		{
			matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0)
			{
				cout << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	for (int j = 0; j < n; j++)
	{
		if (matrix[n-1][j] != 0)
		{
			cout << matrix[n-1][j] << " ";
		}
	}
}
