#pragma once
#include "record.h"

using TInfo = RECORD*;

struct DNODE {
    TInfo info;
    DNODE* next;
    DNODE* prev;

    DNODE(TInfo info) : info(info), next(nullptr), prev(nullptr) {};
};

using ptrDNODE = DNODE*;

