#include "FunctionalHelper.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

#include "../Entities/BankClient.h"
using namespace std;

static bool isnum(const string&);
static int findById(vector<BankClient>, int);
vector<BankClient> findByName(vector<BankClient>, string);
vector<BankClient> findByPhone(vector<BankClient>, string);
vector<BankClient> idQuickSort(vector<BankClient>& list, int start, int end);
bool nameCompare(const BankClient& left, const BankClient& right);

void index(vector<BankClient> list)
{
    for (const auto& i : list)
    {
        i.print();
    }
}

BankClient addClient(const int id)
{
    BankClient client;
    client.id = id;
    wcout << L"Введите фамилию клиента" << '\n';
    cin >> client.lastName;
    wcout << L"Введите имя клиента" << '\n';
    cin >> client.firstName;
    wcout << L"Введите отчество клиента" << '\n';
    cin >> client.patronymic;
    wcout << L"Введите адрес регистрации клиента" << '\n';
    cin >> client.address;
    wcout << L"Введите номер телефона клиента" << '\n';
    cin >> client.phone;
    wcout << L"Введите номер счёта клиента" << '\n';
    cin >> client.account;
    wcout << L"Введите номер карты клиента" << '\n';
    cin >> client.card;
    return client;
}

vector<BankClient> dbsort(vector<BankClient> list)
{
    vector<BankClient> sorted;
    char entrypoint;
    wcout << L"Введите: 1 для сортировки ФИО по алфавиту\n2 для сортировки по номеру\n\"Q\" для отмены:" << '\n';
    cin >> entrypoint;
    while (entrypoint != 'Q' && !isdigit(entrypoint))
    {
        wcout << L"Введите: 1 для сортировки ФИО по алфавиту'\n' 2 для сортировки по номеру '\n' \"Q\" для отмены:" << '\n';
        cin >> entrypoint;
    }
    if (entrypoint == 'Q')
        return list;
    switch (entrypoint)
    {
    case '1':
        sort(begin(list), end(list), nameCompare);
        return list;
    case '2':
        return idQuickSort(list, 0, int(list.size()) - 1);
    default:
        throw exception("Неверно указано число");
    }
}

void search(vector<BankClient> list)
{
    string filter;
    vector<BankClient> found;
    char entrypoint;
    wcout << L"Введите 1 для поиска по ФИО, 2 для поиска по номеру телефона \"Q\" для отмены:" << '\n';
    cin >> entrypoint;
    while (entrypoint != 'Q' && !isdigit(entrypoint))
    {
        wcout << L"Введите 1 для поиска по ФИО, 2 для поиска по номеру телефона \"Q\" для отмены:" << '\n';
        cin >> entrypoint;
    }
    if (entrypoint == 'Q')
        return;
    switch (entrypoint)
    {
    case '1':
        wcout << L"Введите ФИО или его часть, для поиска клиентов:" << '\n';
        cin >> filter;
        found = findByName(list, filter);
        for (const auto& i : found)
            i.print();
        break;
    case '2':
        wcout << L"Введите номер телефона или его часть, для поиска клиентов:" << '\n';
        cin >> filter;
        found = findByPhone(list, filter);
        for (const auto& i : found)
            i.print();
        break;
    default:
        throw exception("Неверно указано число");
    }
}


vector<BankClient> remove(vector<BankClient> list)
{
    string entrypoint;
    while (entrypoint != "Q" && !isnum(entrypoint))
    {
        wcout << L"Введите номер клиента, для его удаления или \"Q\" для отмены:" << '\n';
        cin >> entrypoint;
    }
    if (entrypoint == "Q")
        return list;
    int num = stoi(entrypoint);
    try
    {
        int index = findById(list, num);
        list.erase(list.cbegin() + index);
    }
    catch (const exception& e)
    {
        cout << e.what() << '\n';
    }

    return list;
}


static bool isnum(const string& line)
{
    if (line.begin() == line.end())
        return false;
    for (char i : line)
    {
        if (!isdigit(i))
            return false;
    }
    return true;
}

static int findById(vector<BankClient> list, int id)
{
    for (int i = 0; i < int(list.size()); i++)
    {
        if (list[i].id == id)
            return i;
    }
    throw exception("Клиент с указанным номером не найден");
}

vector<BankClient> findByName(vector<BankClient> list, string name)
{
    vector<BankClient> filtered;
    for (BankClient i : list)
    {
        if (i.lastName.find(name) != string::npos || i.firstName.find(name) != string::npos || i.patronymic.find(name)
            != string::npos)
            filtered.push_back(i);
    }
    if (filtered.empty())
        throw exception("Клиентов с ФИО, содержащим указанную строку не найдено");
    return filtered;
}

vector<BankClient> findByPhone(vector<BankClient> list, string phone)
{
    vector<BankClient> filtered;
    for (BankClient i : list)
    {
        if (i.phone.find(phone) != string::npos)
            filtered.push_back(i);
    }
    if (filtered.empty())
        throw exception("Клиентов с указанным номеров телефона не найдено");
    return filtered;
}

int partition(vector<BankClient>& list, int start, int pivot)
{
    int i = start;
    while (i < pivot)
    {
        if (list[i].id > list[pivot].id && i == pivot - 1)
        {
            swap(list[i], list[pivot]);
            pivot--;
        }
        else if (list[i].id > list[pivot].id)
        {
            swap(list[pivot - 1], list[pivot]);
            swap(list[i], list[pivot]);
            pivot--;
        }
        else i++;
    }
    return pivot;
}

vector<BankClient> idQuickSort(vector<BankClient>& list, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(list, start, end);
        idQuickSort(list, start, pivot - 1);
        idQuickSort(list, pivot + 1, end);
    }
    return list;
}

bool nameCompare(const BankClient& left, const BankClient& right)
{
    return left.lastName + left.firstName + left.patronymic < right.lastName + right.firstName + right.patronymic;
}
