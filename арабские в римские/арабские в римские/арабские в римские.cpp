#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	int lens;
	int s[100];

	cout << "Insert the length of the array" << endl;
	cin >> lens;

	for (int i = 0; i < lens; i++)
	{
		cout << "Insert the next number" << endl;
		cin >> s[i];
	}

	string strans = "";

	//cout << lens << endl;

	int units = 0, tens = 0, hundreds = 0;

	//cout << s[lens - 1] << " " << s[lens - 2] << " " << s[lens - 3] << " " << s[lens - 4] << endl;

	units = s[lens - 1];
	if (lens > 1)
	{
		tens = s[lens - 2];
		if (lens > 2)
			hundreds = s[lens - 3];
	}

	//cout << units << " " << tens << " " << hundreds << " " << endl;

	//---------------------------------

	if (lens > 3)
	{
		int factor = 1;
		for (int i=0; i<lens-3; i++)
		{
			//cout << s[lens - 4 - i] * factor << endl;
			strans.append(s[lens - 4 - i] * factor, 'M');
			factor *= 10;
		}
	}

	//-----hundreds--------------------

	if (hundreds == 9)
	{
		strans += "CM";
	}
	else if (hundreds > 5)
	{
		strans += 'D';
		strans.append(hundreds - 5, 'C');
	}
	else if (hundreds == 5)
	{
		strans += 'D';
	}
	else if (hundreds == 4)
	{
		strans += "CD";
	}
	else
	{
		strans.append(hundreds, 'C');
	}

	//-----tens----------------------

	if (tens == 9)
	{
		strans += "XC";
	}
	else if (tens > 5)
	{
		strans += 'L';
		strans.append(tens - 5, 'X');
	}
	else if (tens == 5)
	{
		strans += 'L';
	}
	else if (tens == 4)
	{
		strans += "XL";
	}
	else
	{
		strans.append(tens, 'X');
	}

	//-----units--------------------

	if (units == 9)
	{
		strans += "IX";
	}
	else if (units > 5)
	{
		strans += 'V';
		strans.append(units - 5, 'I');
	}
	else if (units == 5)
	{
		strans += 'V';
	}
	else if (units == 4)
	{
		strans += "IV";
	}
	else
	{
		strans.append(units, 'I');
	}

	cout << strans;
}
