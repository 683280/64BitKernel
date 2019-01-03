//
// Created by Carl on 2018/6/23.
//

#ifndef INC_64BITKERNEL_GDT_H
#define INC_64BITKERNEL_GDT_H

#include <type.h>

typedef uint64_t gdt_desc;



#pragma pack(1)
struct TSS{
    uint32_t b1;
    uint64_t rsp0;
    uint64_t rsp1;
    uint64_t rsp2;
    uint64_t b2;
    uint64_t ist1;
    uint64_t ist2;
    uint64_t ist3;
    uint64_t ist4;
    uint64_t ist6;
    uint64_t ist7;
    uint64_t b3;
    uint32_t b4;
};

//#define set_gdt
void setup_gdt();
#endif //INC_64BITKERNEL_GDT_H
