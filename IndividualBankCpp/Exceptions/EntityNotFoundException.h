#pragma once
#include <string>
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

class entityNotFoundException : public exception
{
public:
    entityNotFoundException(string msg);
    string what();

private:
    string message;
};
