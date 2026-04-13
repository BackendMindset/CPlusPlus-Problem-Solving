#include <iostream>
#include <cstdlib>
#include <ctime>
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
            : false);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date.Month))
    {
        Date.Year++;
        Date.Month = 1;
        Date.Day = 1;
    }
    else if (IsLastDayInMonth(Date))
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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    if (IsDate1BeforeDate2(Date1, Date2))
    {
        swap(Date1, Date2);
    }

    while (IsDate1BeforeDate2(Date2, Date1))
    {
        Days++;
        Date2 = IncreaseDateByOneDay(Date2);
    }

    if (IncludeEndDay)
        Days++;

    return Days;
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
    Date.Year = ReadYear();
    Date.Month = ReadMonth();
    Date.Day = ReadDay(Date.Month, Date.Year);
    return Date;
}

int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();

    cout << "\nDifference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    return 0;
}