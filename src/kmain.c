//
// Created by Carl on 2018/6/23.
//


#include <multiboot/multiboot.h>
#include <debug/debug.h>
#include <paging/paging.h>



extern multiboot_info_t* multiboot;
extern int multiboot_magic;

void kmain(void){

    if(multiboot_magic == MULTIBOOT_BOOTLOADER_MAGIC){
        kprintf("entry in Multiboot\n");
        setup_paging(multiboot->mem_lower,multiboot->mem_upper);
    }

//    kprintf("kern_end = %x   kern_end = %x    size = %x\n",&kern_start,&kern_end,(uint64_t)&kern_end - (uint64_t)&kern_start);

    while (1){}
}