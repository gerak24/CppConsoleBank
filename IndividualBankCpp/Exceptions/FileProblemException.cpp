#include "FileProblemException.h"
#include <utility>
using namespace std;

fileProblemException::fileProblemException(string msg): message{message}
{
    message = move(msg);
}

string fileProblemException::what()
{
    return message;
}
