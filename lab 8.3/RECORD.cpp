#include <iostream>
#include <fstream>
#include <cstring> 

struct RECORD {
private:
    char date[11]; // Формат даты ДД-ММ-ГГГГ, включая символ конца строки '\0'
    char name[256]; // Достаточно большое, чтобы вместить ФИО или название организации
    char status[10]; // приходу или расход
    int amount;

public:
    RECORD(std::ifstream& file);
    void print() const;
};

RECORD::RECORD(std::ifstream& file) {
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    file.getline(date, 11); 
    file.getline(name, 256); 
    file.getline(status, 10); 
    file >> amount; 
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void RECORD::print() const {
    std::cout << "Дата открытия: " << date << "\n"
        << "Имя/Организация: " << name << "\n"
        << "Статус: " << status << "\n"
        << "Сумма: " << amount << "\n";
}


