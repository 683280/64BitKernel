//
// Created by Carl on 2018/6/23.
//
/**
 * CPU进入长模式
 * 对CPU进行重新初始化
 * 初始化GDT
 * 初始化IDT
 *
 *
 */
#include <debug/debug.h>
#include "x86.h"
#include "idt.h"
#include "gdt.h"


void init_x86(){
//    kprintf("IDT_Table = 0x%08x ,0x%08x ,0x%08x, 0x%08x\n",IDT_Table,&IDT_Table,IDT_Table + 1,((uint64_t)&IDT_Table + 1));
    kprintf("\n");
    setup_gdt();
    kprintf("setup gdt finish\n");
    setup_gate();
    kprintf("setup gate finish\n");

}
