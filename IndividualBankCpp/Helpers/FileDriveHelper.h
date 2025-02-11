#pragma once
#include <vector>
#include "../Entities/BankClient.h"
using namespace std; // NOLINT(clang-diagnostic-header-hygiene)

vector<BankClient> read(string);
void write(string, vector<BankClient>);
void clearFile(string);
