#include <iostream>
#include <fstream>
#include "dlist.h"


int main() {
    setlocale(LC_ALL, "ru");

    std::ifstream file("inp.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    DLIST list(file);
    list.print();
    return 0;
}
