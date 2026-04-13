#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    // Months with 31 days
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 ||
        Month == 8 || Month == 10 || Month == 12)
        return 31;

    // Months with 30 days
    if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
        return 30;

    // February
    return IsLeapYear(Year) ? 29 : 28;
}

short ReadYear()
{
    short Year;
    cout << "Enter Year: ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;

    do
    {
        cout << "Enter Month (1-12): ";
        cin >> Month;

        if (Month < 1 || Month > 12)
            cout << "Invalid month, try again.\n";

    } while (Month < 1 || Month > 12);

    return Month;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    short Days = NumberOfDaysInMonth(Month, Year);

    cout << "\nNumber of Days = " << Days << endl;

    return 0;
}