#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b;
	string ans = "0.";
	cout << "Insert a and, then, b" << endl;
	cin >> a >> b;
	while (a)
	{
		if (ans[ans.length() - 1] != ans[ans.length() - 2])
		{
			if (not(a / b))
			{
				a = a * 10;
				ans += to_string(a / b);
				a -= b * (a / b);
			}
			else
			{
				ans += to_string(a / b);
				a -= b * (a / b);
			}
		}
		else
		{
			ans = ans.substr(0, ans.length() - 2) + '(' + ans[ans.length() - 1] + ')';
			cout << ans;
			return 0;
		}
	}
	cout << ans;
	return 0;
}

