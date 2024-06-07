#include "DLIST.h"
#include <iostream>
#include <cstring>

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

void DLIST::print_list() const {
    ptrDNODE current = head;
    while (current) {
        std::cout << "Клиент: " << current->info->get_customer() << "\n";
        std::cout << "Приход: " << current->info->prihod_sum << "\n";
        std::cout << "Расход: " << current->info->rashod_sum << "\n\n";
        current = current->next;
    }
}

void DLIST::print_max_accounts() const {
    if (!empty()) {
        ptrDNODE max_prihod_node = find_max_prihod(head);
        ptrDNODE max_rashod_node = find_max_rashod(head);

        if (max_prihod_node) {
            std::cout << "Максимальный приход: " << max_prihod_node->info->get_customer() << " на сумму " << max_prihod_node->info->prihod_sum << "\n";
        }
        if (max_rashod_node) {
            std::cout << "Максимальный расход: " << max_rashod_node->info->get_customer() << " на сумму " << max_rashod_node->info->rashod_sum << "\n";
        }
    }
}

bool compare_customers(char* a, char* b) {
    return std::strcmp(a, b) < 0;
}

ptrDNODE find_max_prihod(ptrDNODE head) {
    ptrDNODE max_node = nullptr;
    ptrDNODE current = head;
    while (current) {
        if (!max_node || current->info->prihod_sum > max_node->info->prihod_sum) {
            max_node = current;
        }
        current = current->next;
    }
    return max_node;
}

ptrDNODE find_max_rashod(ptrDNODE head) {
    ptrDNODE max_node = nullptr;
    ptrDNODE current = head;
    while (current) {
        if (!max_node || current->info->rashod_sum > max_node->info->rashod_sum) {
            max_node = current;
        }
        current = current->next;
    }
    return max_node;
}
