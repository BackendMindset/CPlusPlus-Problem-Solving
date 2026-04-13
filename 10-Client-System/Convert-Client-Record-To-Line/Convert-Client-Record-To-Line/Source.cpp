#include <iostream>
#include <string>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadNewClient()
{
    sClient client;

    cout << "Enter Account Number? ";
    getline(cin, client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, client.PinCode);

    cout << "Enter Name? ";
    getline(cin, client.Name);

    cout << "Enter Phone? ";
    getline(cin, client.Phone);

    cout << "Enter Account Balance? ";
    cin >> client.AccountBalance;

    return client;
}

string ConvertRecordToLine(const sClient& client, const string& separator)
{
    string line;
    line += client.AccountNumber + separator;
    line += client.PinCode + separator;
    line += client.Name + separator;
    line += client.Phone + separator;
    line += to_string(client.AccountBalance);

    return line;
}

int main()
{
    cout << "\nPlease enter client data:\n\n";
    sClient client = ReadNewClient();

    cout << "\n\nClient record for saving is:\n";
    cout << ConvertRecordToLine(client, "#//#");

    return 0;
}