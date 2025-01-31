#include "FunctionalHelper.h"
#include <iostream>
#include <ostream>

#include "../Entities/BankClient.h"
using namespace std;

BankClient** initData();
BankClient** includedDb = initData();
BankClient** initData()
{
    const auto initClients = new BankClient*[3];
    initClients[0] = new BankClient("0", "Струговщик", "Алексей", "Евгеньевич", "Ул. Пушкина 1/1", "+79999999999",
                                    "12345678", "123456789098");
    initClients[1] = new BankClient("1", "Кульпин", "Никита", "Никитович", "Ул. Пушкина 1/2", "+78888888888",
                                    "87654321", "890987654321");
    initClients[2] = new BankClient("2", "Никифоров", "Никифор", "Никифорович", "Ул. Пушкина 1/3", "+77777777777",
                                    "12121212", "123123123123");

    return initClients;
}

static void index()
{
   /* for (auto i = 0; i < includedDb; i++)
    {
        cout << i
    }*/
}

static void save()
{
    cout << "" << '\n';
}

static void search()
{
}

static void remove()
{
}
