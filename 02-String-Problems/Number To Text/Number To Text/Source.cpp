#include <iostream>
#include <string>
using namespace std;

string units[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
string teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string powers[] = { "", "Thousand", "Million", "Billion" };

string ConvertSmallNumber(int number)
{
    string result = "";

    if (number >= 100)
    {
        result += units[number / 100] + " Hundred ";
        number %= 100;
    }

    if (number >= 10 && number <= 19)
    {
        result += teens[number - 10] + " ";
        number = 0;
    }
    else if (number >= 20)
    {
        result += tens[number / 10] + " ";
        number %= 10;
    }

    if (number >= 0 && number < 10)
    {
        result += units[number] + " ";
    }

    return result;
}

string NumberToText(int number)
{
    if (number == 0)
        return "Zero";

    if (number < 0)
        return "Negative " + NumberToText(-number);

    string result = "";
    int powerIndex = 0;

    while (number > 0)
    {
        int part = number % 1000;
        if (part > 0)
        {
            result = ConvertSmallNumber(part) + powers[powerIndex] + " " + result;
        }
        number /= 1000;
        powerIndex++;
    }

    return result;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << NumberToText(number) << endl;

    return 0;
}