#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string stLine, string separator)
{
    vector<string> Vstring;
    size_t pos = 0;

    while ((pos = stLine.find(separator)) != string::npos)
    {
        string SWord = stLine.substr(0, pos);
        if (!SWord.empty())
        {
            Vstring.push_back(SWord);
        }
        stLine.erase(0, pos + separator.length());
    }

    if (!stLine.empty())
    {
        Vstring.push_back(stLine);
    }

    return Vstring;
}

sClient ConvertLineToRecord(string stLine, string separator)
{
    vector<string> Vstring = SplitString(stLine, separator);
    sClient Client;

    if (Vstring.size() != 5)
    {
        throw runtime_error("Error: Line does not have the correct number of fields!");
    }

    Client.AccountNumber = Vstring[0];
    Client.PinCode = Vstring[1];
    Client.Name = Vstring[2];
    Client.Phone = Vstring[3];

    try
    {
        Client.AccountBalance = stod(Vstring[4]);
    }
    catch (...)
    {
        throw runtime_error("Error: Invalid Account Balance format!");
    }

    return Client;
}

void PrintClientRecord(const sClient& Client)
{
    cout << "\nThe following is the extracted client record:\n";
    cout << "=============================================\n";
    cout << "Account Number  : " << Client.AccountNumber << '\n';
    cout << "Pin Code        : " << Client.PinCode << '\n';
    cout << "Name            : " << Client.Name << '\n';
    cout << "Phone           : " << Client.Phone << '\n';
    cout << "Account Balance : " << Client.AccountBalance << '\n';
    cout << "=============================================\n";
}

int main()
{
    vector<string> testLines = {
        "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000",
        "B200#//#5678#//#Ahmed Ali#//#078888#//#1500.500000",
        "C300#//#9101#//#Sara Omar#//#077777#//#300.250000"
    };

    for (const string& stLine : testLines)
    {
        try
        {
            sClient Client = ConvertLineToRecord(stLine, "#//#");
            PrintClientRecord(Client);
        }
        catch (const exception& e)
        {
            cerr << "\nError processing line: " << stLine << "\n" << e.what() << '\n';
        }
    }

    return 0;
}