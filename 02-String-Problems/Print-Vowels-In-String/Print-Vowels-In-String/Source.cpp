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

bool IsVowel(char ch)
{
    ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void PrintVowels(const string& text)
{
    for (char ch : text)
    {
        if (IsVowel(ch))
            cout << ch << "   ";
    }
    cout << '\n';
}

int main()
{
    string text = ReadString();
    cout << "Vowels are: ";
    PrintVowels(text);

    return 0;
}