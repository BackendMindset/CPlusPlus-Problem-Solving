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

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : daysInMonth[Month - 1];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year > Date2.Year) return false;
    if (Date1.Month < Date2.Month) return true;
    if (Date1.Month > Date2.Month) return false;
    return Date1.Day < Date2.Day;
}

bool IsLastDayInMonth(stDate Date)
{
    return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        Date.Day = 1;
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? Days + 1 : Days;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
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

    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);
    cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(Period1, true);

    system("pause>0");
    return 0;
}