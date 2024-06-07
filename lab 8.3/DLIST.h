#pragma once

#include "dnode.h"
#include <functional>

struct DLIST {
    DNODE* head;
    DNODE* tail;
    size_t size;

public:
    DLIST(std::ifstream& file1, std::function<bool(char*, char*)> compare);
    ~DLIST();

    bool empty() const;
    void print_list() const;
    void print_max_accounts() const;

private:
    void clear();
    void first_node(TInfo person);
    void insert_before(ptrDNODE node, TInfo person);
    void insert_after(ptrDNODE node, TInfo person);
};

// Функции сравнения
bool compare_customers(char* a, char* b);
ptrDNODE find_max_prihod(ptrDNODE head);
ptrDNODE find_max_rashod(ptrDNODE head);
