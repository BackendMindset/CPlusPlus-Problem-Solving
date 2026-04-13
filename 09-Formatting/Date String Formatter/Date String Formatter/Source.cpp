#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (!sWord.empty())
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (!S1.empty())
    {
        vString.push_back(S1);
    }

    return vString;
}

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
    size_t pos = S1.find(StringToReplace);

    while (pos != string::npos)
    {
        S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);
    }

    return S1;
}

stDate StringToDate(string DateString)
{
    stDate Date;
    vector<string> vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}

string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date (dd/mm/yyyy): ");
    cout << "\nYou entered: " << DateString << endl;

    stDate Date = StringToDate(DateString);

    cout << "\nFormatted Dates:\n";
    cout << FormateDate(Date) << "\n";
    cout << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;
}