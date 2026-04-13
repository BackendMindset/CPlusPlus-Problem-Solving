#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

int NumberOfHoursInMonth(short Year, short Month)
{
    return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month)
{
    return NumberOfMinutesInMonth(Year, Month) * 60;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check: ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    do
    {
        cout << "\nPlease enter a month (1-12) to check: ";
        cin >> Month;
        if (Month < 1 || Month > 12)
        {
            cout << "\nInvalid month entered. Please try again.";
        }
    } while (Month < 1 || Month > 12);

    return Month;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days in Month    [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
    cout << "\nNumber of Hours in Month   [" << Month << "] is " << NumberOfHoursInMonth(Year, Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month);

    return 0;
}