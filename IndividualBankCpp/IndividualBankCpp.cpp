#include <clocale>
#include <iostream>
#include <vector>
#include "Helpers/FunctionalHelper.h"
#include "Entities/BankClient.h"
using namespace std;

BankClient initClients[3]{
    BankClient(0, "Струговщик", "Алексей", "Евгеньевич", "Ул. Пушкина 1/1", "+79999999999",
               "12345678", "123456789098"),
    BankClient(1, "Кульпин", "Никита", "Никитович", "Ул. Пушкина 1/2", "+78888888888",
               "87654321", "890987654321"),
    BankClient(2, "Никифоров", "Никифор", "Никифорович", "Ул. Пушкина 1/3", "+77777777777",
               "12121212", "123123123123")
};
vector<BankClient> includedDb;
void menu();

void main()
{
    setlocale(LC_ALL, "ru-RU"); // NOLINT(cert-err33-c, concurrency-mt-unsafe)
    includedDb.push_back(initClients[0]);
    includedDb.push_back(initClients[1]);
    includedDb.push_back(initClients[2]);
    menu();
}

void menu()
{
    cout << "База клиентов банка \"СPPB\":\n"
        "1 - Для просмотра списка клиентов.\n"
        "2 - Для добавления нового клиента.\n"
        "3 - Для поиска клиента по критерию.\n"
        "4 - Для удаления клиента.\n"
        "5 - Для очистки базы.\n"
        "Q - Для завершения работы.\n";
    char entrypoint;
    cin >> entrypoint;
    while (entrypoint != 'Q')
    {
        switch (entrypoint)
        {
        case '1':
            index(includedDb);
            break;
        case '2':
            includedDb.push_back(addClient(includedDb[includedDb.size()-1].id+1)); // NOLINT(clang-diagnostic-shorten-64-to-32)
            break;
        case '3':
            search(includedDb);
            break;
        case '4':
            includedDb = remove(includedDb);
            break;
        case '5':
            includedDb.clear();
            break;
        default:
            break;
        }
        cout << "Для продолжения введите числа 1-5, введите Q - Для завершения работы.\n";
        cin >> entrypoint;
    }
}
