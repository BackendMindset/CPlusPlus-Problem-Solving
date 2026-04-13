#include <iostream>
#include <fstream>
#include <string>
#include <limits>

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
    getline(cin >> ws, client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, client.PinCode);

    cout << "Enter Name? ";
    getline(cin, client.Name);

    cout << "Enter Phone? ";
    getline(cin, client.Phone);

    cout << "Enter Account Balance? ";
    while (!(cin >> client.AccountBalance))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid Account Balance: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return client;
}

string ConvertRecordToLine(const sClient& client, const string& separator = "#//#")
{
    string line;
    line += client.AccountNumber + separator;
    line += client.PinCode + separator;
    line += client.Name + separator;
    line += client.Phone + separator;
    line += to_string(client.AccountBalance);

    return line;
}

void SaveRecordToFile(const string& fileName, const string& record)
{
    ofstream file(fileName, ios::app);

    if (file.is_open())
    {
        file << record << '\n';
        cout << "\nRecord saved successfully to file: " << fileName << '\n';
    }
    else
    {
        cout << "\nError: Unable to open file!\n";
    }
}

int main()
{
    cout << "\nPlease enter client data:\n\n";
    sClient client = ReadNewClient();

    string record = ConvertRecordToLine(client);
    SaveRecordToFile("Clients.txt", record);

    return 0;
}