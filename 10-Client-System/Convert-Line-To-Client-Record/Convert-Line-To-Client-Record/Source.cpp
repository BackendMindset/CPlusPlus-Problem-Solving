#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(const string& text, const string& separator)
{
    vector<string> parts;
    size_t pos = 0;
    string token = text;

    while ((pos = token.find(separator)) != string::npos)
    {
        string word = token.substr(0, pos);
        if (!word.empty())
            parts.push_back(word);

        token.erase(0, pos + separator.length());
    }

    if (!token.empty())
        parts.push_back(token);

    return parts;
}

sClient ConvertLineToRecord(const string& line, const string& separator = "#//#")
{
    vector<string> data = SplitString(line, separator);

    sClient client;
    client.AccountNumber = data[0];
    client.PinCode = data[1];
    client.Name = data[2];
    client.Phone = data[3];
    client.AccountBalance = stod(data[4]);

    return client;
}

void PrintClientRecord(const sClient& client)
{
    cout << "\nThe following is the extracted client record:\n";
    cout << "\nAccount Number  : " << client.AccountNumber;
    cout << "\nPin Code        : " << client.PinCode;
    cout << "\nName            : " << client.Name;
    cout << "\nPhone           : " << client.Phone;
    cout << "\nAccount Balance : " << client.AccountBalance;
}

int main()
{
    string line = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    sClient client = ConvertLineToRecord(line);

    PrintClientRecord(client);

    return 0;
}