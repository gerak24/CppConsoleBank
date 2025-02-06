#include "FunctionalHelper.h"
#include <iostream>
#include <ostream>
#include <vector>

#include "../Entities/BankClient.h"
using namespace std;

static bool isnum(const string&);
static int findById(vector<BankClient> list, int id);

void index(vector<BankClient> list)
{
    for (const auto& i : list)
    {
        i.print();
    }
}

BankClient addClient(const int id)
{
    BankClient client;
    client.id = id;
    wcout << L"Введите фамилию клиента" << '\n';
    cin >> client.lastName;
    wcout << L"Введите имя клиента" << '\n';
    cin >> client.firstName;
    wcout << L"Введите отчество клиента" << '\n';
    cin >> client.patronymic;
    wcout << L"Введите адрес регистрации клиента" << '\n';
    cin >> client.address;
    wcout << L"Введите номер телефона клиента" << '\n';
    cin >> client.phone;
    wcout << L"Введите номер счёта клиента" << '\n';
    cin >> client.account;
    wcout << L"Введите номер карты клиента" << '\n';
    cin >> client.card;
    return client;
}

void search()
{
}


vector<BankClient> remove(vector<BankClient> list)
{
    string entrypoint;
    while (entrypoint != "Q" && !isnum(entrypoint))
    {
        wcout << L"Введите номер клиента, для его удаления или \"Q\" для отмены:" << '\n';
        cin >> entrypoint;
    }
    if (entrypoint == "Q")
        return list;
    int num = stoi(entrypoint);
    try
    {
        int index = findById(list, num);
        list.erase(list.cbegin() + index);
    }
    catch (const exception& e)
    {
        cout << e.what() << '\n';
    }

    return list;
}


static bool isnum(const string& line)
{
    if (line.begin() == line.end())
        return false;
    for (char i : line)
    {
        if (!isdigit(i))
            return false;
    }
    return true;
}

static int findById(vector<BankClient> list, int id)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].id == id)
            return i;
    }
    throw exception("Клиент с указанным номером не найден");
}
