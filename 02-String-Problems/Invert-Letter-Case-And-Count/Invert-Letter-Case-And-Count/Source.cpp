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

char InvertLetterCase(char ch)
{
    unsigned char c = static_cast<unsigned char>(ch);

    if (isupper(c))
        return static_cast<char>(tolower(c));

    return static_cast<char>(toupper(c));
}

short CountLetter(const string& text, char letter, bool matchCase = true)
{
    short count = 0;
    unsigned char target = static_cast<unsigned char>(letter);

    for (char ch : text)
    {
        if (matchCase)
        {
            if (ch == letter)
                ++count;
        }
        else
        {
            if (tolower(static_cast<unsigned char>(ch)) == tolower(target))
                ++count;
        }
    }

    return count;
}

int main()
{
    string text = ReadString();
    char letter = ReadChar();

    cout << "\nLetter '" << letter << "' Count = " << CountLetter(text, letter);
    cout << "\nLetter '" << letter << "' or '" << InvertLetterCase(letter) << "' Count = " << CountLetter(text, letter, false);

    return 0;
}