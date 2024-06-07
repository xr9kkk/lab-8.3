#pragma once
#include <fstream>
#include <string>
#include <cstring>

struct RECORD {
    char* customer_name;
    std::string date;
    std::string name;
    std::string type;
    double prihod_sum;
    double rashod_sum;

    RECORD(std::ifstream& file) {
        std::string line;

        // Read and ignore the "Дата открытия:" line
        std::getline(file, line);

        // Read the actual date
        std::getline(file, date);

        // Read the name
        std::getline(file, name);

        // Read the transaction type
        std::getline(file, type);

        // Read the amount
        double sum;
        file >> sum;

        // Assign the sum to the correct type
        if (type == "приход") {
            prihod_sum = sum;
            rashod_sum = 0;
        }
        else {
            rashod_sum = sum;
            prihod_sum = 0;
        }

        // Ignore the remaining part of the line after the amount
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    

    char* get_customer()  {
        return customer_name;
    }

    ~RECORD() {
        delete[] customer_name;
    }
};
