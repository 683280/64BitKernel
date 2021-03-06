

bits 32
;Bootloader Header
MEMINFO     equ  1<<0                 ; 获取内存信息
MODULEALIGN equ  1<<1                 ; align loaded modules on page boundaries
MEMMAP      equ  1<<2                 ; 内存分布的缓存区
FLAGS       equ  MODULEALIGN | MEMINFO | MEMMAP ; this is the Multiboot 'flag' field
MAGIC       equ  0x1BADB002           ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + FLAGS)        ; checksum required

section .multiboot
align 4
    MultiBootHeader:
        dd MAGIC
        dd FLAGS
        dd CHECKSUM
        dd 0
        dd 0
        dd 0
        dd 0
        dd 0

        dd 0
        dd 800 ; width
        dd 600 ; height
        dd 32 ; bpp
section .txt
;进入内核
global s_kernel_entry

s_kernel_entry:
        mov [multiboot],ebx
        mov [multiboot_magic],eax
        extern s_init_arch
        call s_init_arch
        jmp $
; save multiboot data
bits 64
global multiboot
global multiboot_magic
multiboot:
        dq  0
multiboot_magic:
        dd  0