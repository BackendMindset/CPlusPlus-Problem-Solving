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

stDate IncreaseDateByXDays(short Days, stDate Date)
{
    while (Days-- > 0)
        Date = IncreaseDateByOneDay(Date);

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    return IncreaseDateByXDays(7, Date);
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
    return IncreaseDateByXDays(Weeks * 7, Date);
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short MaxDay = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > MaxDay)
        Date.Day = MaxDay;

    return Date;
}

stDate IncreaseDateByXMonths(short Months, stDate Date)
{
    while (Months-- > 0)
        Date = IncreaseDateByOneMonth(Date);

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;

    if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
        Date.Day = 28;

    return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
    while (Years-- > 0)
        Date = IncreaseDateByOneYear(Date);

    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    return IncreaseDateByXYears(10, Date);
}

stDate IncreaseDateByXDecades(short Decades, stDate Date)
{
    return IncreaseDateByXYears(Decades * 10, Date);
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    return IncreaseDateByXYears(100, Date);
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    return IncreaseDateByXYears(1000, Date);
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();
    cout << "\nDate After: \n";

    Date1 = IncreaseDateByOneDay(Date1);
    cout << "\n01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDays(10, Date1);
    cout << "\n02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "\n03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXWeeks(10, Date1);
    cout << "\n04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "\n05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXMonths(5, Date1);
    cout << "\n06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "\n07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYears(10, Date1);
    cout << "\n08-Adding 10 years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "\n09-Adding one decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecades(10, Date1);
    cout << "\n10-Adding 10 decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "\n11-Adding one century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "\n12-Adding one millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    return 0;
}