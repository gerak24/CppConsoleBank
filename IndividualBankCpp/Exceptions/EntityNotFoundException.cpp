#include "EntityNotFoundException.h"
#include <utility>
using namespace std;

entityNotFoundException::entityNotFoundException(string msg): message{message}
{
    message = move(msg);
}

string entityNotFoundException::what()
{
    return message;
}
