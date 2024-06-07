#pragma once
#include "DNODE.h"
#include <functional>

struct DLIST {
private:
    ptrDNODE head = nullptr;
    ptrDNODE tail = nullptr;
    size_t size = 0;
public:    // Конструкторы и деструктор
    DLIST() : head(nullptr), tail(nullptr), size(0) {}
    DLIST(std::ifstream& file);
    DLIST(std::ifstream& file, std::function<bool(const char*, const char*)> compare);
    ~DLIST();

    // Методы класса
    bool empty() const { return head == nullptr; }
    void print() const;
    void clear();
    void first_node(RECORD* person);
    void insert_before(ptrDNODE node, RECORD* person);
    void insert_after(ptrDNODE node, RECORD* person);
    ptrDNODE get_head();


};


