#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(const string& text, const string& delimiter)
{
    vector<string> parts;
    size_t pos = 0, start = 0;

    while ((pos = text.find(delimiter, start)) != string::npos)
    {
        parts.push_back(text.substr(start, pos - start));
        start = pos + delimiter.length();
    }

    if (start < text.length())
    {
        parts.push_back(text.substr(start));
    }

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

string ConvertRecordToLine(const sClient& client, const string& separator = "#//#")
{
    return client.AccountNumber + separator +
        client.PinCode + separator +
        client.Name + separator +
        client.Phone + separator +
        to_string(client.AccountBalance);
}

vector<sClient> LoadClientsDataFromFile(const string& fileName)
{
    vector<sClient> clients;
    fstream file(fileName, ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            clients.push_back(ConvertLineToRecord(line));
        }
        file.close();
    }

    return clients;
}

void SaveClientsDataToFile(const string& fileName, const vector<sClient>& clients)
{
    ofstream file(fileName, ios::out);

    if (file.is_open())
    {
        for (const sClient& client : clients)
        {
            file << ConvertRecordToLine(client) << '\n';
        }
        file.close();
    }
}

void PrintClientCard(const sClient& client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number : " << client.AccountNumber;
    cout << "\nPin Code       : " << client.PinCode;
    cout << "\nName           : " << client.Name;
    cout << "\nPhone          : " << client.Phone;
    cout << "\nAccount Balance: " << client.AccountBalance;
}

bool FindClientByAccountNumber(const string& accountNumber, const vector<sClient>& clients, sClient& client)
{
    for (const sClient& c : clients)
    {
        if (c.AccountNumber == accountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}

bool DeleteClientByAccountNumber(const string& accountNumber, vector<sClient>& clients)
{
    sClient client;

    if (!FindClientByAccountNumber(accountNumber, clients, client))
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is not found!\n";
        return false;
    }

    PrintClientCard(client);

    char answer;
    cout << "\n\nAre you sure you want to delete this client? (y/n): ";
    cin >> answer;

    if (tolower(static_cast<unsigned char>(answer)) != 'y')
    {
        cout << "\nOperation canceled.\n";
        return false;
    }

    for (auto it = clients.begin(); it != clients.end(); ++it)
    {
        if (it->AccountNumber == accountNumber)
        {
            clients.erase(it);
            SaveClientsDataToFile(ClientsFileName, clients);
            cout << "\nClient deleted successfully.\n";
            return true;
        }
    }

    return false;
}

string ReadClientAccountNumber()
{
    string accountNumber;
    cout << "\nPlease enter Account Number: ";
    cin >> accountNumber;
    return accountNumber;
}

int main()
{
    vector<sClient> clients = LoadClientsDataFromFile(ClientsFileName);
    string accountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(accountNumber, clients);

    return 0;
}