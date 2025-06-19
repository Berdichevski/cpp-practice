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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = n-2; k >= 0; k--)
			{
				for (int l = n-1; l > k; l--)
				{
//					cout << " upper " << matr[j][i] << " lower " << matr[l][k];
					if (matr[j][i] < matr[l][k])
					{
						cout << "False";
						return 0;
					}
				}
			}
		}
	}
	cout << "True";
	return 0;
}