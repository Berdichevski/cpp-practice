#include <iostream>;
#include <string>;
using namespace std;

int arab(char c)
{
	switch (c)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
}

int main()
{
	int res = 0;
	string s;
	getline(cin, s);
	res = 0;
	for (int i = 0; i < size(s); i++)
	{
		if (arab(s[i]) >= arab(s[i + 1]))
		{
			res += arab(s[i]);
		}
		else
		{
			res -= arab(s[i]);
		}
	}
	cout << res;
	return 0;
}
