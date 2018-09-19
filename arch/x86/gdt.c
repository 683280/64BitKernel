//
// Created by Carl on 2018/6/23.
//

#include "gdt.h"

#define load_gdt(address)\
__asm__ __volatile__(\
"lgdt (%0)"\
::"a"(address)\
)

struct GDT_LOAD gdt_load;

struct GDT_DESC gdt[100];
u32 size = 0;


void setup_gdt(){
    put_gdt(0x0,0xfffff,0xAF9A);
    put_gdt(0x0,0xfffff,0xAF9A);

//    gdt_load.size = 4 * 8 - 1;
//    gdt_load.address = gdt;
//    load_gdt(&gdt_load);

    load_gdt(&gdt_load);
}


int put_gdt(uint32_t base,u32 limit,uint32_t type){

    uint32_t l_gdt = limit & 0xffff;
    l_gdt |= base << 16;

    uint32_t h_gdt = (base >> 16)& 0xff;
    h_gdt |= type << 8;
    h_gdt &= 0xF0FFFF;
    h_gdt |= limit & 0xF0000;
    h_gdt |= base & 0xFF000000;

    h_gdt &= 0xFFFF9FFF;
    size++;
    gdt[size].l = l_gdt;
    gdt[size].h = h_gdt;

    gdt_load.size = (size * 8) - 1;
    return size << 3;
}