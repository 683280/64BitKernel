#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <type.h>

extern u32 kern_start; // Start of the kernel

typedef struct symbol {
    char *name;
    usize_t addr;
    u32 size;
} symbol_t;

extern symbol_t sym_objects[];
extern symbol_t sym_functions[];

symbol_t *sym_find_object(u32 addr, symbol_t *symbols);

#endif
