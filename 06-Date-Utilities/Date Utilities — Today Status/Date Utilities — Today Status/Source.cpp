#include <iostream>
#include <ctime>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

short DayOfWeekOrder(const sDate& today)
{
    short a = (14 - today.Month) / 12;
    short y = today.Year - a;
    short m = today.Month + (12 * a) - 2;
    return (today.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

string DayShortName(short DayOfWeek)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return arrDayNames[DayOfWeek];
}

bool IsEndOfWeek(short DayOfWeek)
{
    return (DayOfWeek == 4);
}

bool IsWeekEnd(short DayOfWeek)
{
    return (DayOfWeek == 5 || DayOfWeek == 6);
}

bool IsBusinessDay(short DayOfWeek)
{
    return !IsWeekEnd(DayOfWeek);
}

int DaysUntilEndOfWeek(short DayOfWeek)
{
    return (4 - DayOfWeek >= 0) ? (4 - DayOfWeek) : 0;
}

int DaysUntilEndOfMonth(const sDate& today)
{
    return NumberOfDaysInAMonth(today.Year, today.Month) - today.Day;
}

int DaysUntilEndOfYear(const sDate& today)
{
    int Days = DaysUntilEndOfMonth(today);
    for (short month = today.Month + 1; month <= 12; month++)
    {
        Days += NumberOfDaysInAMonth(today.Year, month);
    }
    return Days;
}

sDate GetTodayDate()
{
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);
    return {
        static_cast<short>(now.tm_year + 1900),
        static_cast<short>(now.tm_mon + 1),
        static_cast<short>(now.tm_mday)
    };
}

void PrintDate(const sDate& today)
{
    cout << today.Year << "-" << today.Month << "-" << today.Day;
}

int main()
{
    sDate today = GetTodayDate();
    short dayOfWeek = DayOfWeekOrder(today);

    cout << "\nToday is: " << DayShortName(dayOfWeek) << " , ";
    PrintDate(today);
    cout << "\n";

    cout << "\nIs it end of the week?\n";
    cout << (IsEndOfWeek(dayOfWeek) ? "Yes, it is the end of the week.\n" : "No, it is not the end of the week.\n");

    cout << "\nIs it Weekend?\n";
    cout << (IsWeekEnd(dayOfWeek) ? "Yes, it is a weekend.\n" : "No, it is not a weekend.\n");

    cout << "\nIs it a Business day?\n";
    cout << (IsBusinessDay(dayOfWeek) ? "Yes, it is a business day.\n" : "No, it is not a business day.\n");

    cout << "\nDays Until End of the Week: " << DaysUntilEndOfWeek(dayOfWeek) << "\n";
    cout << "\nDays Until End of the Month: " << DaysUntilEndOfMonth(today) << "\n";
    cout << "\nDays Until End of the Year: " << DaysUntilEndOfYear(today) << "\n";

    return 0;
}