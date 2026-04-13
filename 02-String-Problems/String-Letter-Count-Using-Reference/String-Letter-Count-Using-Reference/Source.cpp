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

char ReadChar()
{
    char ch;
    cout << "\nPlease enter a character:\n";
    cin >> ch;
    return ch;
}

void CountLetter(const string& text, char letter, short& exactCount, short& ignoreCaseCount)
{
    exactCount = 0;
    ignoreCaseCount = 0;

    unsigned char target = static_cast<unsigned char>(letter);

    for (char ch : text)
    {
        if (ch == letter)
            ++exactCount;

        if (tolower(static_cast<unsigned char>(ch)) == tolower(target))
            ++ignoreCaseCount;
    }
}

int main()
{
    string text = ReadString();
    char letter = ReadChar();

    short exactCount = 0;
    short ignoreCaseCount = 0;

    CountLetter(text, letter, exactCount, ignoreCaseCount);

    cout << "\nExact Letter '" << letter << "' Count = " << exactCount;
    cout << "\nLetter '" << letter << "' Count (Ignoring Case) = " << ignoreCaseCount;

    return 0;
}