#include <iostream>
#include <tuple>
#include <limits>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
    short DaysV; // vacation days
};

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool IsWeekEnd(short Day, short Month, short Year)
{
    short d = DayOfWeekOrder(Day, Month, Year);
    return (d == 5 || d == 6);
}

bool IsBusinessDay(const stDate& Date)
{
    return !IsWeekEnd(Date.Day, Date.Month, Date.Year);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (++Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
    {
        Date.Day = 1;
        if (++Date.Month > 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
    }
    return Date;
}

stDate GetVacationEndDate(stDate StartDate)
{
    short WorkDays = 0;

    while (WorkDays < StartDate.DaysV)
    {
        StartDate = IncreaseDateByOneDay(StartDate);

        if (IsBusinessDay(StartDate))
            WorkDays++;
    }

    return StartDate;
}

short ReadNumber(string msg, short min, short max)
{
    short x;
    do
    {
        cout << msg;
        cin >> x;
    } while (x < min || x > max);

    return x;
}

stDate ReadFullDate()
{
    stDate d;
    d.Year = ReadNumber("Year: ", 1900, 2100);
    d.Month = ReadNumber("Month: ", 1, 12);
    d.Day = ReadNumber("Day: ", 1, NumberOfDaysInAMonth(d.Month, d.Year));
    d.DaysV = ReadNumber("Vacation Days: ", 1, 60);
    return d;
}

int main()
{
    stDate Start = ReadFullDate();
    stDate End = GetVacationEndDate(Start);

    cout << "\nVacation ends at: "
        << End.Day << "/" << End.Month << "/" << End.Year;

    return 0;
}