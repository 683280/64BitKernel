//
// Created by Carl on 2018/6/23.
//

#ifndef INC_64BITKERNEL_PAE_H
#define INC_64BITKERNEL_PAE_H

#include <type.h>

void setup_pae();
void clear_pagedir(uint64_t *dir);
#endif //INC_64BITKERNEL_PAE_H
