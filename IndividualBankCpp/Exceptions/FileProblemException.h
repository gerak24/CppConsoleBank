#pragma once
#include <exception>
#include <string>

class fileProblemException : public std::exception
{
public:
    fileProblemException(const std::string& msg);

    const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;
};
