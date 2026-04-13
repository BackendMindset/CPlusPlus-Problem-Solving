#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string text;
    cout << "Please enter your string:\n";
    getline(cin, text);
    return text;
}

string TrimLeft(const string& text)
{
    size_t first = text.find_first_not_of(' ');
    if (first == string::npos)
        return "";

    return text.substr(first);
}

string TrimRight(const string& text)
{
    size_t last = text.find_last_not_of(' ');
    if (last == string::npos)
        return "";

    return text.substr(0, last + 1);
}

string TrimLeftRight(const string& text)
{
    return TrimLeft(TrimRight(text));
}

int main()
{
    string text = ReadString();

    cout << "\nTrim Left: " << TrimLeft(text);
    cout << "\nTrim Right: " << TrimRight(text);
    cout << "\nTrim Left & Right: " << TrimLeftRight(text);

    return 0;
}