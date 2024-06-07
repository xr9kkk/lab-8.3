#include "DLIST.h"


DLIST::DLIST(std::ifstream& file) {
    RECORD* customer;
    if (file >> std::ws && !file.eof()) {
        customer = new RECORD(file);
        first_node(customer);
    }
    while (file >> std::ws && !file.eof()) {
        customer = new RECORD(file);
        insert_after(tail, customer);
    }
}

DLIST::DLIST(std::ifstream& file, std::function<bool(const char*, const char*)> compare) {
    RECORD* person;
    while (file >> std::ws && !file.eof()) {
        person = new RECORD(file);
        if (empty()) {
            first_node(person);
        }
        else {
            ptrDNODE place = head;
            while (place && compare(place->info->get_customer(), person->get_customer())) {
                place = place->next;
            }
            if (place) {
                insert_before(place, person);
            }
            else {
                insert_after(tail, person);
            }
        }
    }
}

DLIST::~DLIST() {
    clear();
}

void DLIST::print() const {
    ptrDNODE p = head;
    while (p) {
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

void DLIST::first_node(RECORD* person) {
    head = new DNODE(person);
    tail = head;
    size = 1;
}

void DLIST::insert_after(ptrDNODE ptr, RECORD* elem) {
    ptrDNODE p = new DNODE(elem, ptr->next, ptr);
    if (ptr == tail) {
        tail = p;
    }
    else {
        ptr->next->prev = p;
    }
    ptr->next = p;
    size++;
}

void DLIST::insert_before(ptrDNODE ptr, RECORD* elem) {
    ptrDNODE p = new DNODE(elem, ptr, ptr->prev);
    if (ptr == head) {
        head = p;
    }
    else {
        ptr->prev->next = p;
    }
    ptr->prev = p;
    size++;
}

ptrDNODE DLIST::get_head()
{
    return head;
}