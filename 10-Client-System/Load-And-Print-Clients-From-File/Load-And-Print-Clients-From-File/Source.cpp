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

vector<string> SplitString(string text, const string& delimiter)
{
    vector<string> parts;
    size_t pos = 0;
    string word;

    while ((pos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, pos);
        if (!word.empty())
            parts.push_back(word);

        text.erase(0, pos + delimiter.length());
    }

    if (!text.empty())
        parts.push_back(text);

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

vector<sClient> LoadClientsDataFromFile(const string& fileName)
{
    vector<sClient> clients;
    fstream file(fileName, ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
            clients.push_back(ConvertLineToRecord(line));

        file.close();
    }

    return clients;
}

void PrintClientRecord(const sClient& client)
{
    cout << "| " << setw(15) << client.AccountNumber;
    cout << "| " << setw(10) << client.PinCode;
    cout << "| " << setw(40) << client.Name;
    cout << "| " << setw(12) << client.Phone;
    cout << "| " << setw(12) << client.AccountBalance;
}

void PrintAllClientsData(const vector<sClient>& clients)
{
    cout << "\n\t\t\t\t\tClient List (" << clients.size() << ") Client(s).\n";
    cout << "_______________________________________________________________________________________________\n\n";

    cout << "| " << setw(15) << "Account Number";
    cout << "| " << setw(10) << "Pin Code";
    cout << "| " << setw(40) << "Client Name";
    cout << "| " << setw(12) << "Phone";
    cout << "| " << setw(12) << "Balance";
    cout << "\n_______________________________________________________________________________________________\n\n";

    for (const sClient& client : clients)
    {
        PrintClientRecord(client);
        cout << '\n';
    }

    cout << "\n_______________________________________________________________________________________________\n";
}

int main()
{
    vector<sClient> clients = LoadClientsDataFromFile(ClientsFileName);
    PrintAllClientsData(clients);

    return 0;
}