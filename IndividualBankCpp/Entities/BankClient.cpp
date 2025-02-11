#include "BankClient.h"
#include <iostream>
#include <ostream>
using namespace std;

// dummy constructor
BankClient::BankClient() = default;

// parameterized constructor

BankClient::BankClient(int id, std::string lastName, std::string firstName, std::string patronymic,
                       std::string address, std::string phone, std::string card, std::string account)
{
    if (!phone.empty() || phone.size() > 12)
    {
        this->id = id;
        this->lastName = lastName;
        this->firstName = firstName;
        this->patronymic = patronymic;
        this->address = address;
        this->phone = phone;
        this->card = card;
        this->account = account;
    }
    else
    {
        throw exception("Некорректно указан номер телефона клиента");
    }
}

void BankClient::print() const
{
    wcout << id << L". ФИО: ";
    cout << lastName << " " << firstName << " " << patronymic;
    wcout << L" Адрес: ";
    cout << address;
    wcout << L" Телефон: ";
    cout << phone;
    wcout << L" Номер счёта: ";
    cout << account;
    wcout << L" Номер карты: ";
    cout << card << '\n';
}
