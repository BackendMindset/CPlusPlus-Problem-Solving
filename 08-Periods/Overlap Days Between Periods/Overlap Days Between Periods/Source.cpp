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

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) &&
        !(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year))
    {
        Date.Day = 1;
        if (Date.Month == 12)
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
    if (IsDate1AfterDate2(Date1, Date2))
        return 0;

    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? Days + 1 : Days;
}

int OverlapDays(stPeriod Period1, stPeriod Period2, bool IncludeEndDate = false)
{
    stDate OverlapStart =
        IsDate1BeforeDate2(Period1.StartDate, Period2.StartDate) ? Period2.StartDate : Period1.StartDate;

    stDate OverlapEnd =
        IsDate1BeforeDate2(Period1.EndDate, Period2.EndDate) ? Period1.EndDate : Period2.EndDate;

    if (IsDate1AfterDate2(OverlapStart, OverlapEnd))
        return 0;

    return GetDifferenceInDays(OverlapStart, OverlapEnd, IncludeEndDate);
}

short ReadNumber(string message)
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

    int overlap = OverlapDays(Period1, Period2, true);

    cout << "\nOverlap Days count is: " << overlap << " days.\n";

    system("pause>0");
    return 0;
}