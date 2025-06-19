#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int i = 0;
	while (i < size(s))
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] == ' ')
			{
				for (int j = i+1; j < size(s); j++)
				{
					s[j] = s[j + 1];
				}
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	cout << s;
}