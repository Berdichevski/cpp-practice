#include <iostream>
#include <string>
using namespace std;

int main()
{
	double matrix[100][100];
	int n;
	cout << "Insert the size of the matrix" << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = (j + i + 1) % n + 1;
		}
	}

	cout << endl;

	for (int i = n-1; i >= 0; i--) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
