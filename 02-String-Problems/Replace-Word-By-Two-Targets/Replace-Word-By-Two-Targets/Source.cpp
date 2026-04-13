#include <iostream>
#include <string>

using namespace std;

string ReplaceWord(string text, const string& target1, const string& target2, const string& replacement)
{
    string result;
    string word;
    size_t pos = 0;
    const string delimiter = " ";

    while ((pos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, pos);

        if (word == target1 || word == target2)
            result += replacement + " ";
        else
            result += word + " ";

        text.erase(0, pos + delimiter.length());
    }

    if (text == target1 || text == target2)
        result += replacement;
    else
        result += text;

    return result;
}

int main()
{
    string text = "Welcome to Jordan , Jordan is a nice country";

    cout << "\nModified string:\n";
    cout << ReplaceWord(text, "jordan", "Jordan", "USA");

    return 0;
}