#include "Helpers/FunctionalHelper.h"
#include <clocale>
#include <iostream>
using namespace std;

static void menu()
{
    setlocale(LC_ALL, "Rus"); // NOLINT(cert-err33-c, concurrency-mt-unsafe)
    cout << "База клиентов банка \"СPPB\":\n"
        "1 - Для просмотра списка клиентов.\n"
        "2 - Для добавления нового клиента.\n"
        "Q - Для завершения работы.\n";
    char entrypoint;
    cin >> entrypoint;
    while (entrypoint != 'Q')
    {
        switch (entrypoint)
        {
        case '1':
            FunctionalHelper().index();
            break;
        case '2':
            FunctionalHelper().addClient();
            break;
        case '3':
            FunctionalHelper().search();
            break;
        case '4':
            FunctionalHelper().remove();
            break;
        default:
            break;
        }
        cout << "Для продолжения введите числа 1-5, введите Q - Для завершения работы.\n";
        cin >> entrypoint;
    }
}
