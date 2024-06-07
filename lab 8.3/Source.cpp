#include <iostream>
#include <fstream>
#include "DLIST.h"

void task(DLIST& list);

int main() {
    setlocale(LC_ALL, "ru");

    std::ifstream file("inp.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    DLIST list(file, [](const char* a, const char* b) -> bool {return strcmp(a, b) < 0; });
    /*DLIST list(file);*/
    list.print();
    task(list);
    system("pause");
    return 0;
}



//void task(DLIST& list) {
//    int max_income{};
//    int max_expense{};
//    const char* max_income_customer = nullptr;
//    const char* max_expense_customer = nullptr;
//
//    ptrDNODE p = list.get_head();
//    while (p) {
//        const char* current_name = p->info->get_customer();
//        int total_income = 0;
//        int total_expense = 0;
//
//        ptrDNODE q = list.get_head();
//        while (q) {
//            if (std::strcmp(q->info->get_customer(), current_name) == 0) {
//                if (std::strcmp(q->info->get_status(), "приход") == 0) {
//                    total_income += q->info->get_amount();
//                }
//                else if (std::strcmp(q->info->get_status(), "расход") == 0) {
//                    total_expense += q->info->get_amount();
//                }
//            }
//            q = q->next;
//        }
//
//        if (total_income > max_income) {
//            max_income = total_income;
//            max_income_customer = current_name;
//        }
//
//        if (total_expense > max_expense) {
//            max_expense = total_expense;
//            max_expense_customer = current_name;
//        }
//
//        // Переход к следующему уникальному пользователю
//        while (p && std::strcmp(p->info->get_customer(), current_name) == 0) {
//            p = p->next;
//        }
//    }
//
//    std::cout << "Пользователь с максимальным приходом:\n";
//    std::cout << "Имя/Организация: " << max_income_customer << "\n";
//    std::cout << "Общий приход: " << max_income << "\n";
//   
//
//    std::cout << "\nПользователь с максимальным расходом:\n";
//    std::cout << "Имя/Организация: " << max_expense_customer << "\n";
//    std::cout << "Общий расход: " << max_expense << "\n";
//   
//}
void task(DLIST& list) {
    int max_income{};
    int max_expense{};
    const char* max_income_customer = nullptr;
    const char* max_expense_customer = nullptr;

    ptrDNODE p = list.get_head();
    while (p) {
        const char* current_name = p->info->get_customer();
        int total_income = 0;
        int total_expense = 0;

        // Суммируем все доходы и расходы для текущего клиента
        while (p && std::strcmp(p->info->get_customer(), current_name) == 0) {
            if (std::strcmp(p->info->get_status(), "приход") == 0) {
                total_income += p->info->get_amount();
            }
            else if (std::strcmp(p->info->get_status(), "расход") == 0) {
                total_expense += p->info->get_amount();
            }
            p = p->next;
        }

        // Проверяем и обновляем максимальные значения
        if (total_income > max_income) {
            max_income = total_income;
            max_income_customer = current_name;
        }

        if (total_expense > max_expense) {
            max_expense = total_expense;
            max_expense_customer = current_name;
        }

        // Переход к следующему уникальному клиенту
        while (p && std::strcmp(p->info->get_customer(), current_name) == 0) {
            p = p->next;
        }
    }

    // Вывод результатов
    std::cout << "Пользователь с максимальным приходом:\n";
    if (max_income_customer) {
        std::cout << "Имя/Организация: " << max_income_customer << "\n";
        std::cout << "Общий приход: " << max_income << "\n";
    }
    else {
        std::cout << "Нет данных о приходе\n";
    }

    std::cout << "\nПользователь с максимальным расходом:\n";
    if (max_expense_customer) {
        std::cout << "Имя/Организация: " << max_expense_customer << "\n";
        std::cout << "Общий расход: " << max_expense << "\n";
    }
    else {
        std::cout << "Нет данных о расходе\n";
    }
}





