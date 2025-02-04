#include "BankClient.h"
#include <iostream>
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
    setlocale(LC_ALL, "ru-RU"); // NOLINT(cert-err33-c, concurrency-mt-unsafe)
    cout << id << ". Name: " << lastName + " " + firstName + " " + patronymic +
        " Address: " + address + " Phone: " + phone + " Account: " +
        account + " Card: " << card + '\n';
}
