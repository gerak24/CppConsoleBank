#pragma once
#include <string>

class BankClient
{
public:
    int id;
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    std::string address;
    std::string phone;
    std::string card;
    std::string account;
    BankClient(int id, std::string lastName, std::string firstName, std::string patronymic, std::string address,
               std::string phone, std::string card, std::string account);
    BankClient();
    void print() const;
};
