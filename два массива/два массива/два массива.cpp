#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int len1, len2, q, ibest, jbest;
	int massive1[100];
	int massive2[100];
	int mindifference = 9999999999999;

	cout << "Insert the length of the first array." << endl;
	cin >> len1;
	if (len1 > 100)
	{
		cout << "Error. The array is too big." << endl;
		return 0;
	}

	cout << "Insert the length of the second array." << endl;
	cin >> len2;
	if (len2 > 100)
	{
		cout << "Error. The array is too big." << endl;
		return 0;
	}

	for (int i = 0; i < len1; i++)
	{
		cout << "Insert the next number in the first array." << endl;
		cin >> massive1[i];
	}

	for (int i = 0; i < len2; i++)
	{
		cout << "Insert the next number in the second array." << endl;
		cin >> massive2[i];
	}

	cout << "Insert the target number." << endl;
	cin >> q;

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (q - (massive1[i] + massive2[j]) < 0) //если сумма больше массива, то дальше не идем из-за упорядоченности массива
			{
				ibest = i;
				jbest = j;
				cout << endl;
				cout << "i = " << ibest << "; j = " << jbest << endl;
				return 0;
			}
			if ((abs(q - (massive1[i] + massive2[j])) < mindifference))
			{
				ibest = i;
				jbest = j;
				mindifference = abs(q - (massive1[i] + massive2[j]));
			}
		}
	}
	cout << endl;
	cout << "i = " << ibest << "; j = " << jbest << endl;
}

