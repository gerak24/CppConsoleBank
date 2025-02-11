#include "FileDriveHelper.h"
#include <fstream>
#include <iostream>

#include "../Exceptions/FileProblemException.h"
using namespace std;

vector<BankClient> read(string path)

{
    ifstream file(path);
    vector<BankClient> clients;
    const char* const delimeters = ";";
    char* next_token = NULL;
    string line;
    try
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                vector<std::string> words;
                const char* token = strtok_s(const_cast<char*>(line.data()), delimeters, &next_token);
                while (token != nullptr)
                {
                    words.push_back(token);
                    token = strtok_s(nullptr, delimeters, &next_token);
                }
                clients.emplace_back(stoi(words[0]), words[1], words[2], words[3], words[4], words[5],
                                     words[6], words[7]);
            }
            file.close();
        }
    }
    catch (exception& e) // NOLINT(clang-diagnostic-unused-exception-parameter)
    {
        throw fileProblemException("Произошла проблема, при чтении файла: " + string(e.what()));
    }
    wcout << L"Данные считаны из файла" << '\n';
    return clients;
}

void write(string path, vector<BankClient> list)
{
    try
    {
        ofstream out;
        out.open(path);
        if (out.is_open())
        {
            for (const auto& i : list)
                out << i.id << ";" << i.lastName << ";" << i.firstName << ";" << i.patronymic << ";" << i.address << ";"
                    << i.phone << ";" << i.account << ";" << i.card << '\n';
        }
        out.close();
        wcout << L"Данные записаны в файл" << '\n';
    }
    catch (exception& e) // NOLINT(clang-diagnostic-unused-exception-parameter)
    {
        throw fileProblemException("Произошла проблема, при записи в файл: " + string(e.what()));
    }
}

void clearFile(string path)
{
    try
    {
        ofstream out;
        out.open(path);
        if (out.is_open())
        {
            out.clear();
        }
        out.close();
        wcout << L"Файл очищен" << '\n';
    }
    catch (exception& e) // NOLINT(clang-diagnostic-unused-exception-parameter)
    {
        throw fileProblemException("Произошла проблема, при работе с файлом: " + string(e.what()));
    }
}
