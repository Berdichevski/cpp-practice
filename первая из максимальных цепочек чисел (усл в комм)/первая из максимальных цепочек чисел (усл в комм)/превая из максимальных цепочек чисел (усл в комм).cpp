#include <iostream>
#include <string>
//перва€ из максимальных цепочек чисел последн€€ цифра предыдущего совпадает с первой цифрой следующего
using namespace std;

int main()
{
	int lenarr, a = 0;
	int arr[100];
	int arranswer[100];
	int massive2[100];
	int counter = 0;
	int counterpre = 0;
	int arrunitnum = 0;

	cout << "Insert the length of the array." << endl;
	cin >> lenarr;
	if (lenarr > 100)
	{
		cout << "Error. The array is too big." << endl;
		return 0;
	}

	for (int i = 0; i < lenarr; i++)
	{
		cout << "Insert the next number of the array." << endl;
		cin >> arr[i];
	}

	arr[lenarr] = arr[lenarr] + (arr[lenarr] % 10) * 10;


	for (int i = 1; i < lenarr+1; i++)
	{
		//cout << arr[i - 1] % 10 << " " << static_cast<int>(arr[i] / pow(10, to_string(arr[i]).length() - 1)) << endl;
		if ((arr[i - 1] % 10) == (static_cast<int>(arr[i] / pow(10, to_string(arr[i]).length() - 1))))
		{
			counter += 1;
		}
		else
		{
			if (counter > counterpre)
			{
				arrunitnum = 0;
				for (int j = i - counter - 1; j < i; j++)
				{
					arranswer[arrunitnum] = arr[j];
					arrunitnum++;
				}
				counterpre = counter;
				counter = 0;
			}
		}
		//cout << "Counter = " << counter << " " << "Counterpre = " << counterpre << endl;
	}

	int i = 0;
	while (arranswer[i]>=0)
	{
		cout << arranswer[i] << " ";
		i++;
	}
	return 0;
}
