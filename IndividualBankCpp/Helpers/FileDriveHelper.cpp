#include "FileDriveHelper.h"
#include <fstream>
#include <iostream>

#include "../Exceptions/FileProblemException.h"
using namespace std;

void read(string path)

{
    ifstream file(path);
    string line;
    try
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                cout << line << '\n';
            }
        }
    }
    catch (exception& e)
    {
        throw fileProblemException("Произошла проблема, при чтении файла: ");
    }

    file.close();
}

void write(string path, vector<BankClient> list)
{
    try
    {
        ofstream out;
        out.open(path);
        if (out.is_open())
        {
            out << "Салам алекум" << '\n';
        }
        out.close();
        wcout << L"Данные записаны в файл" << '\n';
    }
    catch (exception& e)
    {
        throw fileProblemException("Произошла проблема, при записи в файл: ");
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
    catch (exception& e)
    {
        throw fileProblemException("Произошла проблема, при работе с файлом: ");
    }
  
}
