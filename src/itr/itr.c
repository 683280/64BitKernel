//
// Created by Carl on 2018/5/29.
//

#include "itr/itr.h"
#include <debug/debug.h>
#include <debug/symbols.h>


struct interrupt_frame
{
    u32 ip;
    u32 cs;
    u32 flags;
    u32 sp;
    u32 ss;
};
void test111(struct interrupt_frame frame){

}

void die(char* fmt,...){
    va_list args;
    kprintf("\e[31m[\e[32m%08x\e[31m]\e[0m  kernel error \n",1);
    kprintf(fmt,args);
}
void do_div_by_zero(){
    kprintf("do_div_by_zero\n");
    while (1){}
}
void do_single_step(){
    kprintf("do_single_step\n");
}
void do_nmi(){
    kprintf("do_nmi\n");
}
void do_breakpoint(){
    kprintf("do_breakpoint\n");
}
void do_overflow(){
    kprintf("do_overflow\n");
}
void do_bounds(){
    kprintf("do_bounds\n");
}
void do_invalid_opcode(){
    kprintf("do_invalid_opcode\n");
    while (1){}
}
void do_coprocessor_not_available(u32 cr2,/* u32 *ebp, */struct pusha_regs regs, struct iret_regs iregs){
    symbol_t * symbol1;
    symbol1 = sym_find_object(iregs.eip,NULL);
    kprintf("<==============[Coprocessor Not Available Exception]====================>\n");
    kprintf("\e[31m[\e[32m%08x\e[31m]\e[0m  kernel error \n",cr2);
    kprintf("cs : %08x  eip : %08x\n",iregs.cs,iregs.eip);

    kprintf("error function = %s\n",symbol1->name);
    while (1){}
}
void do_double_fault(int error_code){
    kprintf("do_double_fault error:%d\n",error_code);
}
void do_coprocessor_segment_overrun(){
    kprintf("do_coprocessor_segment_overrun\n");
}
void do_invalid_task_state_segment(int error_code){
    kprintf("do_coprocessor_segment_overrun error:%d\n",error_code);
}
void do_segment_not_present(int error_code){
    kprintf("do_segment_not_present error:%d\n",error_code);
}
void do_stack_fault(int error_code){
    kprintf("do_stack_fault error:%d\n",error_code);
}
void do_general_protection_fault(int error_code){
    kprintf("do_general_protection_fault error:%d\n",error_code);
}
#define bit_is_set(error_code,position) ((error_code & (1 << position)) >> position)
void do_page_fault(int error_code,u32 cr2,/* u32 *ebp, */struct pusha_regs regs, struct iret_regs iregs){

    kprintf("cr2 = 0x%08x    code = %d    P = %d    W/R = %d    U/S = %d    RSVD = %d    I/D = %d\n",cr2,
            error_code,bit_is_set(error_code,0),bit_is_set(error_code,1),bit_is_set(error_code,2),
            bit_is_set(error_code,3),bit_is_set(error_code,4));
    symbol_t * symbol1;
    symbol1 = sym_find_object(iregs.eip,NULL);
    kprintf("<==============[Page Fault Exception]====================>\n");
    kprintf("\e[31m[\e[32m%08x\e[31m]\e[0m  kernel error \n",cr2);


    kprintf("error code = %d \n",error_code);
    kprintf("cs : %08x  eip : %08x\n",iregs.cs,iregs.eip);
    kprintf("error function = %s\n",symbol1->name);
    while (1){}
}
void do_reserved(u32 cr2,/* u32 *ebp, */struct pusha_regs regs, struct iret_regs iregs){
    symbol_t * symbol1;
    symbol1 = sym_find_object(iregs.eip,NULL);
    kprintf("<==============[Reserved Exception]====================>\n");
    kprintf("\e[31m[\e[32m%08x\e[31m]\e[0m  kernel error \n",cr2);
    kprintf("cs : %08x  eip : %08x\n",iregs.cs,iregs.eip);

    kprintf("error function = %s\n",symbol1->name);
    while (1){}
}
void do_math_fault(){
    kprintf("do_math_fault \n");
}
void do_alignment_check(int error_code){
    kprintf("do_alignment_check error:%d\n",error_code);
}
void do_machine_check(){
    kprintf("do_machine_check\n");
}
void do_simd_floating_point_exception(){
    kprintf("do_simd_floating_point_exception\n");
}
void do_virtualization_exception(){
    kprintf("do_virtualization_exception\n");
}
void do_control_protection_exception(){
    kprintf("do_control_protection_exception\n");
}
//
//void int_test(struct s_stackframe iregs){
//    kprintf("<<<<<<<<<<Print stack frame>>>>>>>>>>\n");
//    kprintf("cr3        = 0x%08x\n",get_pagedir()    );
//    kprintf("cr3        = 0x%08x\n",iregs.cr3       );
//    kprintf("gs         = 0x%08x\n",iregs.gs        );
//    kprintf("fs         = 0x%08x\n",iregs.fs        );
//    kprintf("es         = 0x%08x\n",iregs.es        );
//    kprintf("ds         = 0x%08x\n",iregs.ds        );
//    kprintf("edi        = 0x%08x\n",iregs.edi       );
//    kprintf("esi        = 0x%08x\n",iregs.esi       );
//    kprintf("ebp        = 0x%08x\n",iregs.ebp       );
//    kprintf("kernel_esp = 0x%08x\n",iregs.kernel_esp);
//    kprintf("ebx        = 0x%08x\n",iregs.ebx       );
//    kprintf("edx        = 0x%08x\n",iregs.edx       );
//    kprintf("ecx        = 0x%08x\n",iregs.ecx       );
//    kprintf("eax        = 0x%08x\n",iregs.eax       );
//    kprintf("retaddr    = 0x%08x\n",iregs.retaddr   );
//    kprintf("eip        = 0x%08x\n",iregs.eip       );
//    kprintf("cs         = 0x%08x\n",iregs.cs        );
//    kprintf("eflags     = 0x%08x\n",iregs.eflags    );
//    kprintf("esp        = 0x%08x\n",iregs.esp       );
//    kprintf("ss         = 0x%08x\n",iregs.ss        );
//}