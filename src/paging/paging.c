//
// Created by Carl on 2018/6/1.
//

#include "paging/paging.h"
#include <debug/debug.h>

//4194304  内核占用4MB内存，高12位
uint64_t mem_map[4 * 1024];

//mem_map's Pointer
uint64_t mm_map_index = 0;
//当前内存最大能分多少页 每页4kb 最大内存(kb) / 4
uint64_t mm_max_size = 0;
//
uint64_t curr_max_size = 0;

extern void clear_pagedir(uint64_t *dir);
extern void setup_pae();

extern uint64_t kern_start; // Start of the kernel
extern uint64_t kern_end; // Start of the kernel
//内核大小 k
uint64_t kern_size;

void setup_paging(uint64_t start,uint64_t end){
    mm_max_size = end / 4;
    kern_size = (uint64_t)&kern_end - (uint64_t)&kern_start;

    setup_pae();
    int kernel_used_paging = 0;
    uint64_t offset = 0;
    for (int i = 0; i < 1024; ++i) {
        mem_map[i] = offset;
        offset += 0x1000;
    }

    mm_map_index = 0x200;
    curr_max_size = 1024;
    //将其他的设为 NOT_USED
}

uint64_t get_free_page(){
    uint64_t i = mem_map[mm_map_index];
    mm_map_index++;
    return i;
}
uint64_t get_user_page_dir(){
    uint64_t page_dir = get_free_page();
    clear_pagedir(page_dir);

//    *((uint64_t*)page_dir) = ((uint64_t)&page_tables[0]) | 0x3;
//    *(((uint64_t*)page_dir) + 1) = ((uint64_t)&page_tables[1]) | 0x3;
//    *(((uint64_t*)page_dir) + 2) = ((uint64_t)&page_tables[2]) | 0x3;
//    *(((uint64_t*)page_dir) + 3) = ((uint64_t)&page_tables[3]) | 0x3;

    return page_dir;
}

void free_page(uint64_t page){
    mm_map_index--;
    mem_map[mm_map_index] = page;
}
int inline get_use_page(int page){
    return page & 1;
}
uint64_t inline get_page_address(uint64_t page){
    return page & 0xFFFFF000;
}
void inline set_pagedir(void* dir){
    if(!dir) {
        kprintf("Attempted to set pagedir pointer to NULL!");
        return;
    }
    __asm__ __volatile__("movq %0, %%cr3":: "b"(dir));
}
uint64_t inline *get_pagedir() {
    uint64_t *dir;
    __asm__ __volatile__("movq %%cr3, %0": "=a"(dir));
    return dir;
}


void* alloc_page(int size){
    return alloc_dir_page(get_pagedir(),size);
}
void* alloc_dir_page(uint64_t* page_dir,int size){
    uint64_t* tem_dir;
    uint64_t* page_table;
    int tem = 0;
    int page_index;
    int table_index;

    for (page_index = 0; page_index < PAGING_TAB_SIZE; ++page_index) {
        //get dir pager
        tem_dir = *(page_dir + page_index);
        //页目录是否存在
        if(((uint64_t)tem_dir) & 1 == 0){
            //不存在，分配一页
            *tem_dir = get_free_page() | 0x3;
        }
        tem_dir = (uint64_t)tem_dir & 0xfffff000;
        page_table = *tem_dir;
        for (table_index = 0; table_index < PAGING_TAB_SIZE; ++table_index) {
            if(*page_table & 1){
                tem = 0;
            } else{
                tem++;
                if (tem == size){
                    goto end;
                }
            }
            page_table += 1;
        }
        table_index = 0;
    }
    end:
    if(tem != size){
        return 0;
    }
    tem--;

    page_table -= tem;
    for (int j = 0; j < size; ++j) {
        *(page_table + j)= get_free_page() | 3;
    }
    table_index = (page_index * PAGING_TAB_SIZE) + table_index;
    table_index -= tem;
//    printf("table_index = %d   *page_table = %x\n",table_index,*page_table);
    return table_index << 12;
}