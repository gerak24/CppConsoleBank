#include "FileDriveHelper.h"
#include <fstream>
#include <iostream>

#include "../Exceptions/FileProblemException.h"
using namespace std;

static string encrypt(string), decrypt(string);
static vector<int> getPositions(string);
const string encrypt_key = "Кешью";
string alphabet = "ДЖЗЕЁ7ИЙтуфхМ ФХ09НОП1РСТВУЦЧ4Ш-ЩЪ8КЬ/ЭЮ5ЯабвгдАЛЫБГеёжз+ий2клмноп6рсцч.шщ3ъыьэюя";

vector<BankClient> read(string path)
{
    ifstream file(path);
    vector<BankClient> clients;
    char* next_token = nullptr;
    string line;
    try
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                vector<std::string> words;
                const char* token = strtok_s(const_cast<char*>(line.data()), ";", &next_token);
                while (token != nullptr)
                {
                    words.emplace_back(decrypt(token));
                    token = strtok_s(nullptr, ";", &next_token);
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
                out << encrypt(to_string(i.id)) << ";" << encrypt(i.lastName) << ";" << encrypt(i.firstName) << ";" <<
                    encrypt(i.patronymic)
                    << ";" << encrypt(i.address) << ";" << encrypt(i.phone) << ";" << encrypt(i.account) << ";" <<
                    encrypt(i.card) << '\n';
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

static string encrypt(string data)
{
    const auto key = getPositions(encrypt_key);
    string result;
    for (unsigned int i = 0; i < data.length(); i++)
    {
        const auto itr = find(begin(alphabet), end(alphabet), data[i]);
        result += to_string((distance(alphabet.begin(), itr) + key[i % key.size()]) % 147) + ":";
    }
    return result;
}

static string decrypt(string data)
{
    const auto key = getPositions(encrypt_key);
    int i = 0;
    char* next_token = nullptr;
    vector<char> words;
    const char* token = strtok_s(const_cast<char*>(data.c_str()), ":", &next_token);
    while (token != nullptr)
    {
        int index = atoi(token) - key[i % key.size()];
        if (index < 0) index += 147;
        words.push_back(alphabet[index]); // NOLINT(cert-err34-c)
        i++;
        token = strtok_s(nullptr, ":", &next_token);
    }
    string result(words.begin(), words.end());
    return result;
}

static vector<int> getPositions(string data)
{
    vector<int> result;
    for (unsigned int i = 0; i < data.length(); i++)
    {
        const auto itr = find(begin(alphabet), end(alphabet), data[i]);
        result.push_back(distance(begin(alphabet), itr)); // NOLINT(clang-diagnostic-shorten-64-to-32)
    }
    return result;
}
