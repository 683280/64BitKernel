//
// Created by Carl on 2018/6/23.
//

#include "gdt.h"

#define lgdt(address)\
__asm__ __volatile__(\
"lgdt (%0)"\
::"a"(address)\
)
struct GDT_TR{
    u16 limits;
    uint64_t address;
};

struct gdt_struct{
    uint8_t gdt[8];
};


struct GDT_TR gdt_tr;

struct gdt_struct gdt_tables[100];
u32 size = 0;
void _set_32e_gdt(uint32_t gdt_n,uint64_t type){
    uint64_t* gdt = &gdt_tables[gdt_n];
    *gdt = type << 40;
}
void _set_gdt(uint32_t gdt_n,uint16_t type,uint32_t limit,uint32_t base_addr){

}

void setup_gdt(){
    //代码段
    _set_32e_gdt(1,0x2098);
    //数据段
    _set_32e_gdt(2,0x92);

//    put_gdt(0x0,0xfffff,0xAF9A);
//    put_gdt(0x0,0xfffff,0xAF9A);

//    gdt_load.size = 4 * 8 - 1;
//    gdt_load.address = gdt;
//    load_gdt(&gdt_load);
    gdt_tr.limits = 100;
    gdt_tr.address = &gdt_tables;
    lgdt(&gdt_tr);
//    __asm__ __volatile__("push %rax \n"
//                         "xor %rax,%rax \n"
////                         "mov $0x8,%ax \n"
////                         "push %rax \n"
////                         "push $flag\n"
//                         "jmp 0x8:$flag\n"
//                         "flag:mov $0x10,%ax \n"
//                         "mov %ax,%ds \n"
//                         "mov %ax,%ss \n"
//                         "mov %ax,%gs \n"
//                         "mov %ax,%fs \n"
//                         "mov %ax,%es \n"
//                         "pop %rax \n"
//                         );
}


int put_gdt(uint32_t base,u32 limit,uint32_t type){

//    uint32_t l_gdt = limit & 0xffff;
//    l_gdt |= base << 16;
//
//    uint32_t h_gdt = (base >> 16)& 0xff;
//    h_gdt |= type << 8;
//    h_gdt &= 0xF0FFFF;
//    h_gdt |= limit & 0xF0000;
//    h_gdt |= base & 0xFF000000;
//
//    h_gdt &= 0xFFFF9FFF;
//    size++;
//    gdt[size].l = l_gdt;
//    gdt[size].h = h_gdt;
//
//    gdt_load.size = (size * 8) - 1;
//    return size << 3;
}