#include "DLIST.h"
#include <iostream>
#include <cstring>

DLIST::DLIST(std::ifstream& file)
{
    TInfo customer = new RECORD(file);
    first_node(customer);
    while (!file.eof())
    {
        customer = new RECORD(file);
        insert_after(tail, customer);
    }
    file.close();
}

DLIST::DLIST(std::ifstream& file, std::function<bool(char*, char*)> compare) {
    TInfo person = new RECORD(file);
    first_node(person);

    auto find_place = [this, compare](TInfo elem) -> ptrDNODE {
        ptrDNODE p = head;
        while (p && compare((*(p->info)).get_customer(), (*elem).get_customer()))
            p = p->next;
        return p;
        };

    ptrDNODE place{};
    while (!file.eof()) {
        person = new RECORD(file);
        place = find_place(person);
        if (place)
            insert_before(place, person);
        else
            insert_after(tail, person);
    }
    file.close();
}

DLIST::~DLIST() {
    clear();
}

bool DLIST::empty() const {
    return head == nullptr;
}

void DLIST::print()
{
    ptrDNODE p = head;
    while (p)
    {
        p->info->print();
        p = p->next;
    }
    std::cout << '\n';
}



void DLIST::clear() {
    while (head) {
        ptrDNODE temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void DLIST::first_node(TInfo person) {
    head = new DNODE(person);
    tail = head;
    size = 1;
}

void DLIST::insert_before(ptrDNODE node, TInfo person) {
    ptrDNODE newNode = new DNODE(person);
    newNode->next = node;
    newNode->prev = node->prev;
    if (node->prev) {
        node->prev->next = newNode;
    }
    else {
        head = newNode;
    }
    node->prev = newNode;
    ++size;
}

void DLIST::insert_after(ptrDNODE node, TInfo person) {
    ptrDNODE newNode = new DNODE(person);
    newNode->prev = node;
    newNode->next = node->next;
    if (node->next) {
        node->next->prev = newNode;
    }
    else {
        tail = newNode;
    }
    node->next = newNode;
    ++size;
}





bool compare_customers(char* a, char* b) {
    return std::strcmp(a, b) < 0;
}

