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

int main()
{
    vector<string> words = SplitString(ReadString(), " ");

    cout << "Token count = " << words.size() << '\n';
    for (const string& word : words)
        cout << word << '\n';

    return 0;
}