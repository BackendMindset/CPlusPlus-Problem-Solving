#include <iostream>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool CheckDay(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool CheckMonth(sDate Date)
{
    return (Date.Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (CheckDay(Date) && CheckMonth(Date))
    {
        Date.Year++;
        Date.Month = 1;
        Date.Day = 1;
    }
    else if (CheckDay(Date) && !CheckMonth(Date))
    {
        Date.Month++;
        Date.Day = 1;
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

short ReadDay(short Month, short Year)
{
    short Day;
    do
    {
        cout << "\nPlease enter a Day? ";
        cin >> Day;

        if (Day < 1 || Day > NumberOfDaysInAMonth(Month, Year))
        {
            cout << "Invalid day, please enter a valid day for the given month!\n";
        }
    } while (Day < 1 || Day > NumberOfDaysInAMonth(Month, Year));

    return Day;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    do
    {
        cout << "\nPlease enter a Month? ";
        cin >> Month;

        if (Month < 1 || Month > 12)
        {
            cout << "Invalid month, please enter a number between 1 and 12!\n";
        }
    } while (Month < 1 || Month > 12);

    return Month;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    Date.Day = ReadDay(Date.Month, Date.Year);
    return Date;
}

int main()
{
    sDate Date1 = ReadFullDate();

    Date1 = IncreaseDateByOneDay(Date1);

    cout << "\nDate after adding one day is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    return 0;
}