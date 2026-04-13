#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(const vector<string>& words, const string& delimiter)
{
    if (words.empty())
        return "";

    string result = words[0];
    for (size_t i = 1; i < words.size(); i++)
        result += delimiter + words[i];

    return result;
}

string JoinString(string words[], short length, const string& delimiter)
{
    if (length <= 0)
        return "";

    string result = words[0];
    for (short i = 1; i < length; i++)
        result += delimiter + words[i];

    return result;
}

int main()
{
    vector<string> vString = { "Mohammed", "Faid", "Ali", "Maher" };
    string arrString[] = { "Mohammed", "Faid", "Ali", "Maher" };

    cout << "\nVector after join:\n";
    cout << JoinString(vString, " ");

    cout << "\n\nArray after join:\n";
    cout << JoinString(arrString, 4, " ");

    return 0;
}