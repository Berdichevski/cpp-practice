#include <iostream>
#include <string>

using namespace std;

int main()
{
	int numero;
	cin >> numero;
	int numeropointer;
	numeropointer = numero;
	int length = 0;
	int numeronew;

	while (numeropointer)
	{
		numeropointer = numeropointer / 10;
		length++;
	}

	for (int times = 0; times < length/2+3; times++)
	{
		for (int i = length - 1; i; i--)
		{
			if ((static_cast<int>(numero / pow(10, i)) % 10) < (static_cast<int>(numero / pow(10, i - 1)) % 10))
			{
				numeronew = (static_cast<int>(numero / pow(10, i - 1)) % 10) * pow(10, length - 1);
				for (int j = length - 1; j > i - 1; j--)
				{
					numeronew += (static_cast<int>(numero / pow(10, j)) % 10) * pow(10, j - 1);
				}
				numeronew += (numero % static_cast<int>(pow(10, i - 1)));
				numero = numeronew;
			}
		}
	}
	cout << numero << "\n";
	return 0;
}