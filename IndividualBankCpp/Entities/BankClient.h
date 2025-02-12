#pragma once
#include <string>
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

class BankClient
{
public:
    int id;
    string lastName;
    string firstName;
    string patronymic;
    string address;
    string phone;
    string card;
    string account;
    BankClient(int id, string lastName, string firstName, string patronymic, string address,
               string phone, string card, string account);
    BankClient();
    void print() const;
};
