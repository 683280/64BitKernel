//
// Created by Carl on 2018/6/28.
//

#ifndef INC_64BITKERNEL_SCHED_H
#define INC_64BITKERNEL_SCHED_H

#include <type.h>

typedef struct s_stackframe {
    uint64_t cr3;
    uint64_t gs; /* 0 */
    uint64_t fs; /* 4 */
    uint64_t es; /* 8 */
    uint64_t ds; /* c */
        //popad
    uint64_t edi; /* 10 */
    uint64_t esi; /* 14 pushed by save( ) */
    uint64_t ebp; /* 18 */
    uint64_t kernel_esp; /* 1c <- 'popad' will ignore it */
    uint64_t ebx; /* 20 */
    uint64_t edx; /* 24 */
    uint64_t ecx; /* 28 */
    uint64_t eax; /* 2c */

    uint64_t retaddr; /* 30 return addr for kernel.asm::save( ) */
    //iretd
    uint64_t eip; /* 34 */
    uint64_t cs; /* 38 */
    uint64_t eflags; /* 3c | pushed by CPU during interrupt */

    uint64_t esp; /* 40 */
    uint64_t ss; /* 44 */
}STACK_FRAME;

//进程体
typedef struct s_proc {
    STACK_FRAME regs; /* 保存cpu当前状态 */
    int p_flag;
    u8 priority;    //优先级
    u8 time_film;   //时间片
    u32 pid; // 进程ID 对应在proc_list中的位置
    char p_name[16]; /* 进程名称 */
}PROCESS;

typedef struct s_tss {
    u32	backlink;
    u32	esp0;		/* stack pointer to use during interrupt */
    u32	ss0;		/*   "   segment  "  "    "        "     */
    u32	esp1;
    u32	ss1;
    u32	esp2;
    u32	ss2;
    u32	cr3;
    u32	eip;
    u32	flags;
    u32	eax;
    u32	ecx;
    u32	edx;
    u32	ebx;
    u32	esp;
    u32	ebp;
    u32	esi;
    u32	edi;
    u32	es;
    u32	cs;
    u32	ss;
    u32	ds;
    u32	fs;
    u32	gs;
    u32	ldt;
    u16	trap;
    u16	iobase;	/* I/O位图基址大于或等于TSS段界限，就表示没有I/O许可位图 */
    /*u8	iomap[2];*/
}TSS;

#endif //INC_64BITKERNEL_SCHED_H
