#include <iostream>;
using namespace std;

int main()
{
	const int N = 1000;
	int arr[N];
	int len, sum;
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
	cin >> sum;
	int i = 0, j = len-1;
	while (i < j)
	{
		if (sum == arr[i] + arr[j])
		{
			cout << i << j;
			return 0;
		}
		else if (sum > arr[i] + arr[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	cout << "there is no suitable pair";
}