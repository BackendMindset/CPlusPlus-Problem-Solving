#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string text;
    cout << "\nPlease enter your string:\n";
    getline(cin, text);
    return text;
}

int CountVowels(const string& text)
{
    int count = 0;

    for (char ch : text)
    {
        char lower = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
            ++count;
    }

    return count;
}

int main()
{
    string text = ReadString();
    cout << "\nThe string contains " << CountVowels(text) << " vowels.\n";

    return 0;
}