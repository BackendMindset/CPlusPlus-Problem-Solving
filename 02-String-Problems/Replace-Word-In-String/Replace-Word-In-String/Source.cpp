#include <iostream>
#include <string>

using namespace std;

string ReplaceWord(string text, const string& target, const string& replacement)
{
    size_t pos = 0;

    while ((pos = text.find(target, pos)) != string::npos)
    {
        text.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }

    return text;
}

int main()
{
    string text = "Welcome to Jordan, Jordan is a nice country";

    cout << "\nModified string:\n";
    cout << ReplaceWord(text, "Jordan", "USA");

    return 0;
}