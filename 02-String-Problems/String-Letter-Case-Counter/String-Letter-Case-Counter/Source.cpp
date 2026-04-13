#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string message;
    cout << "Please enter your string:\n";
    getline(cin, message);
    return message;
}

enum class LetterCase
{
    SmallLetters,
    CapitalLetters
};

int CountLettersByCase(const string& text, LetterCase letterCase)
{
    int counter = 0;

    for (char ch : text)
    {
        unsigned char c = static_cast<unsigned char>(ch);

        if (letterCase == LetterCase::CapitalLetters && isupper(c))
            counter++;
        else if (letterCase == LetterCase::SmallLetters && islower(c))
            counter++;
    }

    return counter;
}

int main()
{
    string message = ReadString();

    cout << "\nString Length = " << message.length() << '\n';
    cout << "Capital Letters Count = " << CountLettersByCase(message, LetterCase::CapitalLetters) << '\n';
    cout << "Small Letters Count = " << CountLettersByCase(message, LetterCase::SmallLetters) << '\n';

    return 0;
}