//
// Created by Carl on 2018/6/23.
//

#ifndef INC_64BITKERNEL_X86_H
#define INC_64BITKERNEL_X86_H
//保存CPU当前状态
struct CPU_Frame{
    uint64_t gs;
    uint64_t fs;
    uint64_t es;
    uint64_t ds;

    uint64_t r16;
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    uint64_t r11;
    uint64_t r10;
    uint64_t r9 ;
    uint64_t r8 ;

    uint64_t rsi;
    uint64_t rdi;
    uint64_t rdp;

    uint64_t rdx;
    uint64_t rcx;
    uint64_t rbx;
    uint64_t rax;

    uint64_t eip;
    uint64_t cs;
    uint64_t eflags;
    uint64_t esp;
    uint64_t ss;
};
void init_x86();
#endif //INC_64BITKERNEL_X86_H
