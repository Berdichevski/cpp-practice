#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int i = 0, j = size(s) - 1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			cout << "NOT palyndrome";
			return 0;
		}
		else
		{
			i++;
			j--;
		}
	}
	cout << "Palyndrome!";
	return 0;
}