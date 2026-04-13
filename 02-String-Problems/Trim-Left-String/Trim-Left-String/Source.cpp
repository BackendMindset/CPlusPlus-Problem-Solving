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

int main()
{
    string text = ReadString();
    cout << "\nTrim Left: " << TrimLeft(text);

    return 0;
}