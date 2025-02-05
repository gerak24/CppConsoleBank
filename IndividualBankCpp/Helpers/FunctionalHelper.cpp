#include "FunctionalHelper.h"
#include <iostream>
#include <ostream>
#include <vector>

#include "../Entities/BankClient.h"
using namespace std;

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
    wcout  << L"Введите фамилию клиента" << '\n';
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

void remove()
{
}
