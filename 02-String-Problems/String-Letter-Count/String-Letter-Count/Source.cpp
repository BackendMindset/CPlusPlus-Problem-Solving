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

short CountExactLetter(const string& text, char letter)
{
    short count = 0;

    for (char ch : text)
    {
        if (ch == letter)
            ++count;
    }

    return count;
}

short CountLetterIgnoreCase(const string& text, char letter)
{
    short count = 0;
    unsigned char target = static_cast<unsigned char>(letter);

    for (char ch : text)
    {
        if (tolower(static_cast<unsigned char>(ch)) == tolower(target))
            ++count;
    }

    return count;
}

int main()
{
    string text = ReadString();
    char letter = ReadChar();

    cout << "\nExact Letter '" << letter << "' Count = " << CountExactLetter(text, letter);
    cout << "\nLetter '" << letter << "' Count (Ignoring Case) = " << CountLetterIgnoreCase(text, letter);

    return 0;
}