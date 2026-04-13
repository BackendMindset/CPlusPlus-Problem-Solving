#include <iostream>
#include <tuple>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(const stDate& Date1, const stDate& Date2)
{
    if (tie(Date1.Year, Date1.Month, Date1.Day) < tie(Date2.Year, Date2.Month, Date2.Day))
        return Before;

    if (tie(Date1.Year, Date1.Month, Date1.Day) > tie(Date2.Year, Date2.Month, Date2.Day))
        return After;

    return Equal;
}

bool IsOverlapPeriods(const stPeriod& Period1, const stPeriod& Period2)
{
    return !(CompareDates(Period2.EndDate, Period1.StartDate) == Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) == After);
}

short ReadNumber(const string& message)
{
    short number;
    cout << message;
    cin >> number;
    return number;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadNumber("\nEnter Day: ");
    Date.Month = ReadNumber("Enter Month: ");
    Date.Year = ReadNumber("Enter Year: ");
    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

int main()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap.\n";
    else
        cout << "\nNo, Periods Do Not Overlap.\n";

    return 0;
}