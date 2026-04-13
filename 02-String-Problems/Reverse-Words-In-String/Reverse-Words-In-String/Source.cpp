#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
    string text;
    cout << "Please enter your string:\n";
    getline(cin, text);
    return text;
}

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

string ReverseWordsInString(const string& text)
{
    vector<string> words = SplitString(text, " ");
    string result;

    for (auto it = words.rbegin(); it != words.rend(); ++it)
    {
        result += *it;
        if (next(it) != words.rend())
            result += " ";
    }

    return result;
}

int main()
{
    string text = ReadString();

    cout << "\n\nString after reversing words:\n";
    cout << ReverseWordsInString(text);

    return 0;
}