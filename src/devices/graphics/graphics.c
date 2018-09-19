//
// Created by Carl on 2018/6/23.
//

#include "devices/graphics/graphics.h"

u8* vga_char_mode = 0xb8000;

void put_char(u8 c,int color,int x,int y){
    int offset = ((y * 80) + x) * 2;
    *(vga_char_mode + offset) = c;
    *(vga_char_mode + offset + 1) = (u8)color;
}