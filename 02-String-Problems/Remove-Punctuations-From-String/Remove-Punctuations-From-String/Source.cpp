#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string RemovePunctuationsFromString(const string& text)
{
    string result;

    for (char ch : text)
    {
        if (!ispunct(static_cast<unsigned char>(ch)))
            result += ch;
    }

    return result;
}

int main()
{
    string text = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

    cout << "Original String:\n" << text;
    cout << "\n\nPunctuations Removed:\n" << RemovePunctuationsFromString(text);

    return 0;
}