#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
    // Leap Year Rules:
    // 1. Divisible by 4
    // 2. Not divisible by 100
    // 3. Unless divisible by 400

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadYear()
{
    short Year;
    cout << "Enter a year: ";
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes, it is a Leap Year.\n";
    else
        cout << "\nNo, it is NOT a Leap Year.\n";

    return 0;
}