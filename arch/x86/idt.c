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
irq_handler irq_handlers[] = {s_div_by_zero,                           // 0x0
                              s_single_step,                           // 0x1
                              s_nmi ,                                  // 0x2
                              s_breakpoint,                            // 0x3
                              s_overflow,                              // 0x4
                              s_bounds,                                // 0x5
                              s_invalid_opcode,                        // 0x6
                              s_coprocessor_not_available,             // 0x7
                              s_double_fault,                          // 0x8
                              s_coprocessor_segment_overrun,           // 0x9
                              s_invalid_task_state_segment,            // 0xa
                              s_segment_not_present,                   // 0xb
                              s_stack_fault,                           // 0xc
                              s_general_protection_fault,              // 0xd
                              s_page_fault,                            // 0xe
                              s_reserved,                              // 0xf
                              s_math_fault,                            // 0x10
                              s_alignment_check,                       // 0x11
                              s_machine_check,                         // 0x12
                              s_simd_floating_point_exception,         // 0x13
                              s_virtualization_exception,              // 0x14
                              s_control_protection_exception};         // 0x15