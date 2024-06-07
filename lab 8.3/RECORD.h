#pragma once

#include <iostream>
#include <fstream>
#include <cstring> 

struct RECORD {
private:
    char date[11]; 
    char name[256]; 
    char status[10]; 
    int amount;

public:
    RECORD(std::ifstream& file);
    void print() const;
    const char* get_customer() const {
        return name;
    }
    int get_amount()
    {
        return amount;
    }
    char* get_status() {
        return status;
    }
};
