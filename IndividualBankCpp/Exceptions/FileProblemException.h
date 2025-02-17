#pragma once
#include <string>
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

class fileProblemException : public exception
{
public:
    fileProblemException(string msg);
    string what();

private:
    string message;
};
