#pragma once
#include "record.h"

using TInfo = RECORD*;

struct DNODE
{
    TInfo info;
    DNODE* next;
    DNODE* prev;

    DNODE(TInfo info, DNODE* next = nullptr, DNODE* prev = nullptr) :
        info(info), next(next), prev(prev) {}

    ~DNODE() {
        delete info; // Освобождаем память, выделенную для RECORD
        next = nullptr;
        prev = nullptr;
    }
};

using ptrDNODE = DNODE*;
