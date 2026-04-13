#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> SplitString(string text, const string& delimiter)
{
    vector<string> words;
    size_t pos = 0;
    string word;

    while ((pos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, pos);
        if (!word.empty())
            words.push_back(word);

        text.erase(0, pos + delimiter.length());
    }

    if (!text.empty())
        words.push_back(text);

    return words;
}

string JoinString(const vector<string>& words, const string& delimiter)
{
    if (words.empty())
        return "";

    string result = words[0];
    for (size_t i = 1; i < words.size(); i++)
        result += delimiter + words[i];

    return result;
}

string ToLowerString(string text)
{
    for (char& ch : text)
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));

    return text;
}

string ReplaceWordInStringUsingSplit(string text, const string& wordToReplace, const string& replacement, bool matchCase)
{
    vector<string> words = SplitString(text, " ");

    for (string& word : words)
    {
        if (matchCase)
        {
            if (word == wordToReplace)
                word = replacement;
        }
        else
        {
            if (ToLowerString(word) == ToLowerString(wordToReplace))
                word = replacement;
        }
    }

    return JoinString(words, " ");
}

int main()
{
    string text = "Welcome to Jordan , jordan is a nice country";

    cout << "\nOriginal String:\n" << text;
    cout << "\n\nReplace with match case:\n" << ReplaceWordInStringUsingSplit(text, "jordan", "USA", true);
    cout << "\n\nReplace without match case:\n" << ReplaceWordInStringUsingSplit(text, "jordan", "USA", false);

    return 0;
}