#include <iostream>
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

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (Date1.Year < Date2.Year) return Before;
    if (Date1.Year > Date2.Year) return After;
    if (Date1.Month < Date2.Month) return Before;
    if (Date1.Month > Date2.Month) return After;
    if (Date1.Day < Date2.Day) return Before;
    if (Date1.Day > Date2.Day) return After;
    return Equal;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
    return !(CompareDates(Date, Period.StartDate) == Before ||
        CompareDates(Date, Period.EndDate) == After);
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
    cout << "\nEnter Period:";
    stPeriod Period = ReadPeriod();

    cout << "\nEnter Date to check:\n";
    stDate Date = ReadFullDate();

    cout << (IsDateInPeriod(Date, Period) ? "\nYes, Date is within period\n" : "\nNo, Date is NOT within period\n");

    system("pause>0");
    return 0;
}