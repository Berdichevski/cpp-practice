#include <iostream>
#include <string>

using namespace std;

int main()
{
	int pointer, number, givenpointer, difference;
	string str = "";
	cin >> givenpointer;
	number = 0;
	pointer = 2;
    int prenumber1 = 1;
    int prenumber2 = 0;

    cout << prenumber2 << "\n" << prenumber1 << "\n";

    while (givenpointer > pointer)
    {
        pointer += to_string(number).length();
        number = prenumber1 + prenumber2;
        prenumber2 = prenumber1;
        prenumber1 = number;
        cout << number << "\n";
    }

    difference = pointer - givenpointer;
//    cout << difference << "\n";

    while (difference > 0)
    {
        number /= 10;
        difference--;
    }

    cout << number % 10 << endl;

    return 0;
}
