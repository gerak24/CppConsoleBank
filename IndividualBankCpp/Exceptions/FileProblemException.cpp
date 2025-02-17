#include "FileProblemException.h"

fileProblemException::fileProblemException(string& msg): message{message}
{
    message = move(msg);
}

string fileProblemException::what()
{
    return message;
}