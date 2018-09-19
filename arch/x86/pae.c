//
// Created by Carl on 2018/6/23.
//

#include <debug/debug.h>
#include "pae.h"


//typedef
uint64_t PML4T[512] __align(0x1000);
uint64_t pae_dir_ptr_tab[512] __align(0x1000);
uint64_t pae_page_dir[512] __align(0x1000);
uint64_t pae_page_tab[512] __align(0x1000);


void setup_pae(){
//    clear_pagedir(&PML4T);
//    clear_pagedir(&pae_dir_ptr_tab);
//    clear_pagedir(&pae_page_dir);
//    clear_pagedir(&pae_page_tab);

//    PML4T[0] = ((uint64_t)&pae_dir_ptr_tab) | 3;
    kprintf("PML4T[0] = %d \n", ((uint64_t)&pae_dir_ptr_tab) | 3);
}

void clear_pagedir(uint64_t *dir){
    int i = 0;
    for(i = 0; i < 512; i++){
        dir[i] = 2; // supervisor, rw, not present.
    }
}