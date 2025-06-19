#include <iostream>
using namespace std;

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int daysSinceStartOfYear(int day, int month, int year) {
    int days = 0;
    for (int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    days += day - 1;
    return days;
}

int main() {
    int day, month, year;
    cout << "Insert day, month and year: " << "\n";
    cin >> day >> month >> year;
    int days = daysSinceStartOfYear(day, month, year);
    cout << "The amount of days from the first of January," << year << " until the given date is " << days << "\n";
    return 0;
}



/*switch (m - 1)
{
case 11: S += 30;
case 10: S += 31;
case 9: S += 30;
case 8: S += 31;
case 7: S += 31;
case 6: S += 30;
case 5: S += 31;
case 4: S += 30;
case 3: S += 31;
case 2: isLeapYear(year) ? 29 : 28;
case 1: S += 31;
}
*/