//
// Created by 13342 on 2017/8/6.
//

#ifndef NEWKERNEL_IO_H
#define NEWKERNEL_IO_H

#include <type.h>

#define outb(port,value) \
__asm__ ("outb %%al,%%dx"::"a" (value),"d" (port))


#define outw(port,value) \
__asm__ ("outw %%ax,%%dx"::"a" (value),"d" (port))

#define outl(port,value) \
__asm__ ("outl %%eax,%%dx"::"a" (value),"d" (port))


#define inb(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al":"=a" (_v):"d" (port)); \
_v; \
})
#define inw(port) ({ \
unsigned short _v; \
__asm__ volatile ("inw %%dx,%%ax":"=a" (_v):"d" (port)); \
_v; \
})
#define inl(port) ({ \
unsigned int _v; \
__asm__ volatile ("inl %%dx,%%eax":"=a" (_v):"d" (port)); \
_v; \
})
#define io_wait() __asm__("nop")
//#define out_byte(port,data) \
//__asm__ ("outb %%al,%%dx\n" \
//		"\tjmp 1f\n" \
//		"1:\tjmp 1f\n" \
//		"1:"::"a" (data),"d" (port));
//#define in_byte(port) ({\
//unsigned char _v; \
//__asm__ volatile ("inb %%dx,%%al\n" \
//	"\tjmp 1f\n" \
//	"1:\tjmp 1f\n" \
//	"1:":"=a" (_v):"d" (port)); \
//_v; \
//})

#endif //NEWKERNEL_IO_H
