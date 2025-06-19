#include <iostream>

int main()
{
	int targetNumber = 77;
	int sampleNumber;

	do 
	{
		std::cin >> sampleNumber;
		if (sampleNumber > targetNumber)
		{
			std::cout << "number > target" << "\n";
		}
		if (sampleNumber < targetNumber)
		{
			std::cout << "number < target" << "\n";
		}
	} while (sampleNumber != targetNumber);
	std::cout << "You win!";
	return 0;
}

