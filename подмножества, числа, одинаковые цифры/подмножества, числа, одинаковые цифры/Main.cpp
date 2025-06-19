#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool containsSameDigits(int number)
{
	bool* digits = new bool[10] {0};
	while (number)
	{
		int rem = number % 10;
		if (digits[rem])
		{
			return 1;
		}
		else
		{
			digits[rem] = 1;
		}
		number /= 10;
	}
	return 0;
}

void printSubset(int* set, int n, int bitmask, ofstream& outFile)
{
	string tempString = "";
	tempString += "{";
	bool allContainSameDigits = 1;
	bool isFirst = true;
	for (int i = 0; i < n; i++)
	{
		if (bitmask & (1 << i))
		{
			if (!isFirst)
			{
				tempString += ", ";
			}
			tempString += to_string(set[i]);
			if (!containsSameDigits(set[i]))
			{
				allContainSameDigits = 0;
			}
			isFirst = false;
		}
	}
	tempString += "}";
	if (allContainSameDigits)
	{
		outFile << tempString << endl;
	}
}

void generateSubsets(int* set, int n, ofstream& outFile)
{
	int numSubsets = 1 << n;

	for (int bitmask = 0; bitmask < numSubsets; bitmask++)
	{
		printSubset(set, n, bitmask, outFile);
	}
}

int main()
{
	int n;
	cin >> n;
	int* set = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> set[i];
	}

	ofstream outFile("out.txt");

	if (outFile.is_open())
	{
		generateSubsets(set, n, outFile);
		outFile.close();
		cout << "Done!" << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}

	delete[] set;

	return 0;
}