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

void addClient()
{
    cout << "" << '\n';
}

void search()
{
}

void remove()
{
}
