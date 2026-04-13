#include <iostream>
#include <tuple>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool PeriodsOverlap(stDate s1, stDate e1, stDate s2, stDate e2)
{
    return !(tie(e1.Year, e1.Month, e1.Day) < tie(s2.Year, s2.Month, s2.Day) ||
        tie(e2.Year, e2.Month, e2.Day) < tie(s1.Year, s1.Month, s1.Day));
}

short ReadNum(string msg)
{
    short x;
    cout << msg;
    cin >> x;
    return x;
}

stDate ReadDate()
{
    return { ReadNum("Year: "), ReadNum("Month: "), ReadNum("Day: ") };
}

int main()
{
    cout << "\nPeriod 1\n";
    stDate s1 = ReadDate();
    stDate e1 = ReadDate();

    cout << "\nPeriod 2\n";
    stDate s2 = ReadDate();
    stDate e2 = ReadDate();

    cout << (PeriodsOverlap(s1, e1, s2, e2)
        ? "\nOverlap"
        : "\nNo Overlap");

    return 0;
}