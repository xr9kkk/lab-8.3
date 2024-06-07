#pragma once
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
const int n = 35;

struct RECORD {
    char date[n], status[n], customer[n];
    int amount;

    RECORD(std::ifstream& file) 
    {
        file.ignore(); 
        file.getline(date, n); 
        file.getline(customer, n); 
        file.getline(status, n); 
        file >> amount; 
        file.ignore(); 
        if (!file.eof()) 
        {
            char delim_line[255];
            file.getline(delim_line, 255); 
        }
    }

    int amount_getter()
    {
        return amount;
    }

    char* get_customer() 
    {
        return customer;
    }

    char status_getter() {
        return status[n];
    }

    ~RECORD() {
        delete[] customer;
    }
    void print()
    {
        std::cout << date << '\n';
        std::cout << status << '\n';
        std::cout << customer<< '\n';
        std::cout << amount << '\n';
    }
};
