#pragma once
#include <exception>
#include <string>

class entityNotFoundException :public std::exception
{
public:
    entityNotFoundException(const std::string & msg);

    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};
