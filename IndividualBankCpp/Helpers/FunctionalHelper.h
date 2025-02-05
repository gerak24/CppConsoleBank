#pragma once
#include <vector>

#include "../Entities/BankClient.h"
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

BankClient addClient(int id);
void index(vector<BankClient> );
void search();
void remove();
