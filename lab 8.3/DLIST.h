#pragma once

#include "dnode.h"
#include <functional>


struct DLIST {
    DNODE* head;
    DNODE* tail;
    size_t size;

public:
    DLIST() { head = nullptr, tail = nullptr; }
    DLIST(std::ifstream& file);
    DLIST(std::ifstream& file, std::function<bool(char*, char*)> compare);
    ~DLIST();

    bool empty() const;
    void print();
    

private:
    void clear();
    void first_node(TInfo person);
    void insert_before(ptrDNODE node, TInfo person);
    void insert_after(ptrDNODE node, TInfo person);
    
};


bool compare_customers(char* a, char* b);

