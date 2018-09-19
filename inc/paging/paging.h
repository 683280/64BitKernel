//
// Created by Carl on 2018/6/1.
//

#ifndef NEWKERNEL_PAGING_H
#define NEWKERNEL_PAGING_H

#include <type.h>
#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB
#define MAX_MEM_SIZE 4 * GB

#define PAGING_TAB_SIZE 512

//1048576
#define PAGING_PAGES (MAX_MEM_SIZE >> 12)

#define USED 100

#define PAGING_P        1
#define PAGING_W        1  << 1
#define PAGING_U        1  << 2
#define PAGING_PWT      1  << 3
#define PAGING_PCD      1  << 4
#define PAGING_A        1  << 5
#define PAGING_D        1  << 6
#define PAGING_PAT      1  << 7
#define PAGING_G        1  << 8

#define enable_paging() \
 __asm__ volatile( \
"movq %cr0,%rax\n" \
"orq $0x80000000,%rax\n" \
"movq %rax,%cr0\n" \
);
#define disable_paging() \
 __asm__ volatile( \
"movl %cr0,%eax\n" \
"xorl $0x80000000,%eax\n" \
"movl %eax,%cr0\n" \
);

#define set_cr3(address){ \
int _offset = address; \
_offset &= 0xffffffff; \
__asm__ __volatile__("movq %%rax,%%cr3\n" \
::"a"(_offset)    \
:);}


struct {
    uint64_t cr3;

};

typedef uint64_t PTE_DESC;

//extern uint64_t mem_map[4][1024];
uint64_t kernel_cr3;

void setup_paging(uint64_t start,uint64_t end);
uint64_t get_user_page_dir();
uint64_t get_free_page();
void free_page(uint64_t page);

void set_pagedir(void* dir);
uint64_t *get_pagedir();
uint64_t get_page_address(uint64_t page);
int get_use_page(int page);

void* alloc_page(int size);
void* alloc_dir_page(uint64_t* page_dir,int size);
#endif //NEWKERNEL_PAGING_H
