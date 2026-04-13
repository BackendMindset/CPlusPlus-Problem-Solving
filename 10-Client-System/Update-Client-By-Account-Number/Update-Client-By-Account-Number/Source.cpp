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
    cout << "\n=============================================\n";
    cout << "Account Number  : " << client.AccountNumber << '\n';
    cout << "Pin Code        : " << client.PinCode << '\n';
    cout << "Name            : " << client.Name << '\n';
    cout << "Phone           : " << client.Phone << '\n';
    cout << "Account Balance : " << fixed << setprecision(2) << client.AccountBalance << '\n';
    cout << "=============================================\n";
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

void UpdateClientDetails(sClient& client)
{
    cout << "\nEnter new Pin Code: ";
    getline(cin, client.PinCode);

    cout << "Enter new Name: ";
    getline(cin, client.Name);

    cout << "Enter new Phone: ";
    getline(cin, client.Phone);

    cout << "Enter new Account Balance: ";
    cin >> client.AccountBalance;
}

bool UpdateClientByAccountNumber(vector<sClient>& clients)
{
    string accountNumber;
    cout << "\nPlease enter the Account Number of the client to update: ";
    cin >> accountNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    sClient client;
    if (!FindClientByAccountNumber(accountNumber, clients, client))
    {
        cout << "\nError: Client with Account Number (" << accountNumber << ") not found.\n";
        return false;
    }

    PrintClientCard(client);

    char confirm;
    cout << "\nAre you sure you want to update this client? (y/n): ";
    cin >> confirm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (tolower(static_cast<unsigned char>(confirm)) != 'y')
    {
        cout << "\nOperation canceled by the user.\n";
        return false;
    }

    for (sClient& c : clients)
    {
        if (c.AccountNumber == accountNumber)
        {
            UpdateClientDetails(c);
            break;
        }
    }

    SaveClientsDataToFile(ClientsFileName, clients);
    cout << "\nClient updated successfully.\n";
    return true;
}

void ProcessClientUpdates(vector<sClient>& clients)
{
    char again = 'y';

    do
    {
        system("cls");
        UpdateClientByAccountNumber(clients);

        cout << "\nDo you want to update another client? (y/n): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (tolower(static_cast<unsigned char>(again)) == 'y');
}

int main()
{
    vector<sClient> clients = LoadClientsDataFromFile(ClientsFileName);
    ProcessClientUpdates(clients);

    cout << "\nThank you for using the Client Management System!\n";
    return 0;
}