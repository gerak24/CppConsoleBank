#include "BankClient.h"
#include <iostream>
#include <ostream>
using namespace std;

// dummy constructor
BankClient::BankClient()
= default;

// parameterized constructor

BankClient::BankClient(int id, std::string lastName, std::string firstName, std::string patronymic,
                       std::string address, std::string phone, std::string card, std::string account)
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
