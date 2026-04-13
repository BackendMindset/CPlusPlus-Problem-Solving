#include <iostream>
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

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day > 1)
    {
        Date.Day--;
    }
    else
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    }

    return Date;
}

stDate DecreaseDateByDays(stDate Date, int DaysToSubtract)
{
    while (DaysToSubtract-- > 0)
        Date = DecreaseDateByOneDay(Date);

    return Date;
}

stDate DecreaseDateByMonths(stDate Date, int MonthsToSubtract)
{
    while (MonthsToSubtract-- > 0)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        short MaxDay = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > MaxDay)
            Date.Day = MaxDay;
    }

    return Date;
}

stDate DecreaseDateByYears(stDate Date, int YearsToSubtract)
{
    while (YearsToSubtract-- > 0)
    {
        Date.Year--;

        if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
            Date.Day = 28;
    }

    return Date;
}

short ReadNumber(const string& prompt, short minVal, short maxVal)
{
    short num;
    do
    {
        cout << prompt;
        cin >> num;

        if (num < minVal || num > maxVal)
            cout << "Invalid input, please enter a value between " << minVal << " and " << maxVal << ".\n";
    } while (num < minVal || num > maxVal);

    return num;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Year = ReadNumber("\nEnter Year: ", 1, 9999);
    Date.Month = ReadNumber("\nEnter Month (1-12): ", 1, 12);
    Date.Day = ReadNumber("\nEnter Day: ", 1, NumberOfDaysInAMonth(Date.Month, Date.Year));
    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();

    Date1 = DecreaseDateByDays(Date1, 1);
    cout << "\nSubtracting 1 day: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByDays(Date1, 10);
    cout << "\nSubtracting 10 days: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByDays(Date1, 7);
    cout << "\nSubtracting 1 week: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByDays(Date1, 70);
    cout << "\nSubtracting 10 weeks: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByMonths(Date1, 1);
    cout << "\nSubtracting 1 month: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByMonths(Date1, 5);
    cout << "\nSubtracting 5 months: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByYears(Date1, 1);
    cout << "\nSubtracting 1 year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByYears(Date1, 10);
    cout << "\nSubtracting 10 years: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByYears(Date1, 10);
    cout << "\nSubtracting another 10 years: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByYears(Date1, 100);
    cout << "\nSubtracting 1 century: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByYears(Date1, 100);
    cout << "\nSubtracting another century: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByYears(Date1, 1000);
    cout << "\nSubtracting 1 millennium: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    return 0;
}