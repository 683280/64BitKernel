//
// Created by Carl on 2018/6/23.
//

#include "idt.h"

extern void s_div_by_zero();
extern void s_single_step();
extern void s_nmi();
extern void s_breakpoint();
extern void s_overflow();
extern void s_bounds();
extern void s_invalid_opcode();
extern void s_coprocessor_not_available();
extern void s_double_fault();
extern void s_coprocessor_segment_overrun();
extern void s_invalid_task_state_segment();
extern void s_segment_not_present();
extern void s_stack_fault();
extern void s_general_protection_fault();
extern void s_page_fault();
extern void s_reserved();
extern void s_math_fault();
extern void s_alignment_check();
extern void s_machine_check();
extern void s_simd_floating_point_exception();
extern void s_virtualization_exception();
extern void s_control_protection_exception();

typedef void (*irq_handler)();
#pragma pack(1)
struct IDT_TR{
    uint16_t limits;
    uint64_t base_address;
}__align(4);

struct gate_struct IDT_Table[255];

struct IDT_TR idt_tr;
//irq_handler irq_handlers[] = {s_div_by_zero,                           // 0x0
//                              s_single_step,                           // 0x1
//                              s_nmi ,                                  // 0x2
//                              s_breakpoint,                            // 0x3
//                              s_overflow,                              // 0x4
//                              s_bounds,                                // 0x5
//                              s_invalid_opcode,                        // 0x6
//                              s_coprocessor_not_available,             // 0x7
//                              s_double_fault,                          // 0x8
//                              s_coprocessor_segment_overrun,           // 0x9
//                              s_invalid_task_state_segment,            // 0xa
//                              s_segment_not_present,                   // 0xb
//                              s_stack_fault,                           // 0xc
//                              s_general_protection_fault,              // 0xd
//                              s_page_fault,                            // 0xe
//                              s_reserved,                              // 0xf
//                              s_math_fault,                            // 0x10
//                              s_alignment_check,                       // 0x11
//                              s_machine_check,                         // 0x12
//                              s_simd_floating_point_exception,         // 0x13
//                              s_virtualization_exception,              // 0x14
//                              s_control_protection_exception};         // 0x15

void setup_gate(){
    set_trap_gate(0,1,s_div_by_zero);
    set_trap_gate(1,1,s_single_step);
    set_intr_gate(2,1,s_nmi);
    set_system_gate(3,1,s_breakpoint);
    set_system_gate(4,1,s_overflow);
    set_system_gate(5,1,s_bounds);
    set_trap_gate(6,1,s_invalid_opcode);
    set_trap_gate(7,1,s_coprocessor_not_available);
    set_trap_gate(8,1,s_double_fault);
    set_trap_gate(9,1,s_coprocessor_segment_overrun);
    set_trap_gate(10,1,s_invalid_task_state_segment);
    set_trap_gate(11,1,s_segment_not_present);
    set_trap_gate(12,1,s_stack_fault);
    set_trap_gate(13,1,s_general_protection_fault);
    set_trap_gate(14,1,s_page_fault);
    //15 Intel reserved. Do not use.
    set_trap_gate(16,1,s_math_fault);
    set_trap_gate(17,1,s_alignment_check);
    set_trap_gate(18,1,s_machine_check);
    set_trap_gate(19,1,s_simd_floating_point_exception);
    set_trap_gate(20,1,s_virtualization_exception);

    idt_tr.limits = 255;
    idt_tr.base_address = &IDT_Table;
    lidt(&idt_tr);
}
