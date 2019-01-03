//
// Created by Carl on 2018/6/23.
//


#include <multiboot/multiboot.h>
#include <debug/debug.h>
#include <paging/paging.h>


extern multiboot_info_t* multiboot;
extern int multiboot_magic;
struct Memory_Formate {
//    uint32_t base_addr_low;
//    uint32_t base_addr_high;
    uint64_t base_addr;
//    uint32_t length_low;
//    uint32_t length_high;
    uint64_t length;
    uint32_t type;
};

void print_mem_map(uint64_t pMem,uint32_t length){
    uint32_t size;
    uint64_t offset;
    uint64_t TotalMem = 0;
    uint8_t *pAddr;
    struct Memory_Formate *p = NULL;

    kprintf("Display Physics Address MAP,Type(1:RAM,2:ROM or Reserved,3:ACPI Reclaim Memory,4:ACPI NVS Memory,Others:Undefine) \n");
    pAddr = pMem;
    while(1) {
        size = *pAddr;
        p = (struct Memory_Formate *)(pAddr + offset + 4);
//        kprintf("Address:%#010x,%08x   Length:%#010x,%08x   Type:%#010x\n",p->base_addr_high,p->base_addr_low,p->length_high,p->length_low,p->type);
        kprintf("\e[32mAddress:%#018lx   Length:%#018lx   Type:%#010x\e[0m\n",p->base_addr,p->length,p->type);
        if(p->type == 1) {
            TotalMem +=  p->length;
        }
        offset += size + 4;
        if(offset >= length)
            break;
    }
    kprintf("OS Can Used Total RAM:%#018lx\n",TotalMem);
}
void kmain(void){
    kprintf("kernel loaded...\n");
    if(multiboot_magic == MULTIBOOT_BOOTLOADER_MAGIC){
        kprintf("entry in Multiboot\n");
        kprintf("memory length %d\n",multiboot->mem_upper - multiboot->mem_lower);
        setup_paging(multiboot->mem_lower,multiboot->mem_upper);
        print_mem_map(multiboot->mmap_addr,multiboot->mmap_length);
    }
//    init_itr();

    while (1){}
}