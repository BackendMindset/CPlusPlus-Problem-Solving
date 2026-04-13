#include <iostream>
#include <algorithm>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(const stDate& Date1, const stDate& Date2)
{
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year > Date2.Year) return false;
    if (Date1.Month < Date2.Month) return true;
    if (Date1.Month > Date2.Month) return false;
    return Date1.Day < Date2.Day;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(const stDate& Date)
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
    int Sign = 1;

    if (IsDate1BeforeDate2(Date2, Date1))
    {
        swap(Date1, Date2);
        Sign = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    if (IncludeEndDay)
        Days++;

    return Days * Sign;
}

short ReadYear()
{
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    do
    {
        cout << "Please enter a Month (1-12): ";
        cin >> Month;

        if (Month < 1 || Month > 12)
            cout << "Invalid month, try again!\n";
    } while (Month < 1 || Month > 12);

    return Month;
}

short ReadDay(short Month, short Year)
{
    short Day;
    do
    {
        cout << "Please enter a Day: ";
        cin >> Day;

        if (Day < 1 || Day > NumberOfDaysInAMonth(Month, Year))
            cout << "Invalid day for this month, try again!\n";
    } while (Day < 1 || Day > NumberOfDaysInAMonth(Month, Year));

    return Day;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Year = ReadYear();
    Date.Month = ReadMonth();
    Date.Day = ReadDay(Date.Month, Date.Year);
    return Date;
}

int main()
{
    cout << "\nEnter the first date:\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter the second date:\n";
    stDate Date2 = ReadFullDate();

    cout << "\nDifference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).\n";

    return 0;
}