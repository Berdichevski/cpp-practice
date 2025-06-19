#include <iostream>;
#include <string>;
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int wordcounter = 1;
	int sentencecounter = 0;
	int wordsinsentence[100];
	int j = 0;
	int i = 0;
	while (i < size(s))
	{
		if ((s[i] == '.') && (s[i + 1] == '.') && (s[i + 2] == '.') && (s[i + 3] == ' '))
		{
			sentencecounter++;
			wordsinsentence[j] = wordcounter;
			j++;
			wordcounter = 1;
			i += 3;
		}
		else if ((s[i] == '.') && (s[i + 1] == '.') && (s[i + 2] == '.'))
		{
			sentencecounter++;
			wordsinsentence[j] = wordcounter;
			j++;
			wordcounter = 1;
			i += 2;
		}
		else if ((s[i] == '!') && (s[i + 1] == '?') && (s[i + 2] == ' '))
		{
			sentencecounter++;
			wordsinsentence[j] = wordcounter;
			j++;
			wordcounter = 1;
			i += 2;
		}
		else if ((s[i] == '!') && (s[i + 1] == '?'))
		{
			sentencecounter++;
			wordsinsentence[j] = wordcounter;
			j++;
			wordcounter = 1;
			i++;
		}
		else if (((s[i] == '.') && (s[i + 1] == ' ')) || ((s[i] == '!') && (s[i + 1] == ' ')) || ((s[i] == '?') && (s[i + 1] == ' ')))
		{
			sentencecounter++;
			wordsinsentence[j] = wordcounter;
			j++;
			wordcounter = 1;
			i++;
		}
		else if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
		{
			sentencecounter++;
			wordsinsentence[j] = wordcounter;
			j++;
			wordcounter = 1;
		}
		else if (((s[i] == ',') && (s[i + 1] == ' ')) || ((s[i] == ':') && (s[i + 1] == ' ')) || ((s[i] == ';') && (s[i + 1] == ' ')))
		{
			wordcounter++;
			i++;
		}
		else if ((s[i] == ',') || (s[i] == ':') || (s[i] == ';') || (s[i] == '-') || (s[i] == ' '))
		{
			wordcounter++;
		}
		i++;
	}
	int sum = 0;
	for (i = 0; i < sentencecounter; i++)
	{
		sum += wordsinsentence[i];
	}
	for (i = 0; i < sentencecounter; i++)
	{
		cout << wordsinsentence[i] << endl;
	}
	double average_1 = sum / sentencecounter;
	double average_2 = sum % sentencecounter;
	cout << sentencecounter << endl;
	cout << average_1 << "." << average_2;
}
	