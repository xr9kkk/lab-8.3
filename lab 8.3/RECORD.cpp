#include <iostream>
#include <fstream>
#include <cstring> 

struct RECORD {
private:
    char date[11]; // ������ ���� ��-��-����, ������� ������ ����� ������ '\0'
    char name[256]; // ���������� �������, ����� �������� ��� ��� �������� �����������
    char status[10]; // ������� ��� ������
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
    std::cout << "���� ��������: " << date << "\n"
        << "���/�����������: " << name << "\n"
        << "������: " << status << "\n"
        << "�����: " << amount << "\n";
}


