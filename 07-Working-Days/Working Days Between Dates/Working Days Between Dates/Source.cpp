#include <iostream>
#include <tuple>
#include <limits>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

constexpr inline bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    constexpr short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    const string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
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

bool IsWeekEnd(short Day, short Month, short Year)
{
    short DayIndex = DayOfWeekOrder(Day, Month, Year);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(const stDate& Date)
{
    return !IsWeekEnd(Date.Day, Date.Month, Date.Year);
}

int GetWorkingDaysBetweenDates(stDate StartDate, stDate EndDate)
{
    int WorkDays = 0;

    while (tie(StartDate.Year, StartDate.Month, StartDate.Day) < tie(EndDate.Year, EndDate.Month, EndDate.Day))
    {
        if (IsBusinessDay(StartDate))
            WorkDays++;

        StartDate = IncreaseDateByOneDay(StartDate);
    }

    return WorkDays;
}

short ReadNumberInRange(const string& prompt, short min, short max)
{
    short num;
    do
    {
        cout << prompt << " (" << min << "-" << max << "): ";
        cin >> num;

        if (cin.fail() || num < min || num > max)
        {
            cout << "Invalid input! Please enter a number between " << min << " and " << max << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            break;

    } while (true);

    return num;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Year = ReadNumberInRange("Enter Year", 1900, 2100);
    Date.Month = ReadNumberInRange("Enter Month", 1, 12);
    Date.Day = ReadNumberInRange("Enter Day", 1, NumberOfDaysInAMonth(Date.Month, Date.Year));
    return Date;
}

int main()
{
    cout << "\nVacation Starts:\n";
    stDate StartDate = ReadFullDate();

    stDate EndDate;
    do
    {
        cout << "\nVacation Ends:\n";
        EndDate = ReadFullDate();

        if (!(tie(StartDate.Year, StartDate.Month, StartDate.Day) < tie(EndDate.Year, EndDate.Month, EndDate.Day)))
            cout << "Error: The end date must be after the start date. Please enter again.\n";

    } while (!(tie(StartDate.Year, StartDate.Month, StartDate.Day) < tie(EndDate.Year, EndDate.Month, EndDate.Day)));

    cout << "\nVacation From : " << DayShortName(DayOfWeekOrder(StartDate.Day, StartDate.Month, StartDate.Year))
        << " , " << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year;

    cout << "\nVacation To   : " << DayShortName(DayOfWeekOrder(EndDate.Day, EndDate.Month, EndDate.Year))
        << " , " << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year;

    cout << "\nActual Vacation Duration (excluding weekends): "
        << GetWorkingDaysBetweenDates(StartDate, EndDate) << " working day(s).\n";

    return 0;
}