//
// Created by Carl on 2018/6/23.
//

#ifndef INC_64BITKERNEL_GDT_H
#define INC_64BITKERNEL_GDT_H

#include <type.h>

typedef uint64_t gdt_desc;

struct GDT_LOAD{
    u16 size;
    uint64_t address;
};

struct GDT_DESC{
    uint32_t l;
    uint32_t h;
};

void setup_gdt();
#endif //INC_64BITKERNEL_GDT_H
