#include <debug/symbols.h>

symbol_t sym_objects[] = {
    { "printbuf", 0x0000000000116020, 1024 },
    { "is_esc", 0x0000000000116428, 4 },
    { "buff", 0x0000000000116440, 256 },
    { "buff_loc", 0x0000000000116424, 4 },
    { "forc", 0x0000000000104000, 1 },
    { "bkgc", 0x0000000000116540, 1 },
    { "ansi_to_vga", 0x0000000000103480, 16 },
    { "_GLOBAL_OFFSET_TABLE_", 0x0000000000105848, 0 },
    { "big_mm", 0x0000000000116560, 16 },
    { "x", 0x0000000000116421, 1 },
    { "gdt_tables", 0x000000000010f000, 800 },
    { "PML4T", 0x0000000000110000, 4096 },
    { "sym_objects", 0x0000000000104020, 792 },
    { "pae_dir_ptr_tab", 0x0000000000111000, 4096 },
    { "vga_char_mode", 0x0000000000104010, 8 },
    { "IDT_Table", 0x0000000000112000, 4080 },
    { "kernel_cr3", 0x0000000000106000, 8 },
    { "pae_page_tab", 0x0000000000113000, 4096 },
    { "low_mm", 0x0000000000116550, 16 },
    { "size", 0x0000000000116588, 4 },
    { "y", 0x0000000000116420, 1 },
    { "gdt_tr", 0x0000000000114000, 10 },
    { "kern_size", 0x0000000000106008, 8 },
    { "pae_page_dir", 0x0000000000115000, 4096 },
    { "mm_map_index", 0x0000000000116580, 8 },
    { "sym_functions", 0x0000000000104340, 2016 },
    { "curr_max_size", 0x0000000000116570, 8 },
    { "page_mem_size", 0x0000000000104008, 4 },
    { "mem_map", 0x0000000000106020, 32768 },
    { "min_page_size", 0x0000000000104004, 4 },
    { "mm_max_size", 0x0000000000116578, 8 },
    { "idt_tr", 0x0000000000116000, 12 },
    {"EOS", 0xFFFFFFFFFFFFFFFF, 0x0}
};

symbol_t sym_functions[] = {
    { "number", 0x0000000000100150, 750 },
    { "init_serial", 0x0000000000101060, 105 },
    { "write_serial", 0x00000000001010e0, 27 },
    { "do_double_fault", 0x0000000000101310, 26 },
    { "vsprintf", 0x0000000000100440, 1506 },
    { "get_pagedir", 0x0000000000102170, 4 },
    { "new_page_tag", 0x0000000000101700, 166 },
    { "strndup", 0x0000000000101f30, 93 },
    { "do_page_fault", 0x00000000001013d0, 197 },
    { "sym_find_object", 0x0000000000101100, 84 },
    { "do_stack_fault", 0x0000000000101390, 26 },
    { "do_bounds", 0x0000000000101250, 24 },
    { "get_boundary_tag", 0x00000000001019e0, 82 },
    { "do_machine_check", 0x0000000000101560, 24 },
    { "do_control_protection_exc", 0x00000000001015c0, 24 },
    { "get_use_page", 0x0000000000102120, 6 },
    { "do_segment_not_present", 0x0000000000101370, 26 },
    { "put_gdt", 0x00000000001023f0, 2 },
    { "test111", 0x0000000000101160, 2 },
    { "set_pagedir", 0x0000000000102140, 40 },
    { "free_page", 0x00000000001020f0, 35 },
    { "enable_irq", 0x00000000001016c0, 56 },
    { "init_x86", 0x00000000001029a0, 85 },
    { "malloc", 0x0000000000101b20, 51 },
    { "itoa", 0x0000000000101ec0, 109 },
    { "do_invalid_opcode", 0x0000000000101270, 30 },
    { "free_big_mem", 0x0000000000101b00, 29 },
    { "do_math_fault", 0x0000000000101520, 24 },
    { "no_long_mode", 0x0000000000102370, 2 },
    { "within", 0x0000000000101fb0, 54 },
    { "strcat", 0x0000000000101d40, 376 },
    { "do_virtualization_excepti", 0x00000000001015a0, 24 },
    { "do_nmi", 0x00000000001011f0, 24 },
    { "dprintf", 0x0000000000100a30, 154 },
    { "setup_paging", 0x0000000000101ff0, 140 },
    { "get_page_address", 0x0000000000102130, 9 },
    { "setup_gdt", 0x00000000001023b0, 64 },
    { "do_breakpoint", 0x0000000000101210, 24 },
    { "new_boundary_tag", 0x0000000000101970, 103 },
    { "do_alignment_check", 0x0000000000101540, 26 },
    { "isalpha", 0x0000000000101fa0, 16 },
    { "is_transmit_empty", 0x00000000001010d0, 14 },
    { "strdup", 0x0000000000101be0, 124 },
    { "_set_gdt", 0x00000000001023a0, 2 },
    { "setup_8250a", 0x00000000001015e0, 108 },
    { "setup_pae", 0x0000000000102940, 38 },
    { "do_coprocessor_not_availa", 0x0000000000101290, 120 },
    { "get_free_page", 0x0000000000102080, 35 },
    { "get_low_mem", 0x0000000000101850, 181 },
    { "do_simd_floating_point_ex", 0x0000000000101580, 24 },
    { "free_low_mem", 0x0000000000101910, 82 },
    { "get_high_mem", 0x0000000000101a40, 190 },
    { "print_mem_map", 0x0000000000100030, 135 },
    { "die", 0x0000000000101170, 57 },
    { "strcmp", 0x0000000000101c60, 213 },
    { "vga_put", 0x0000000000100d40, 535 },
    { "send_pic_eoi", 0x0000000000101650, 26 },
    { "new_low_tag", 0x00000000001017b0, 146 },
    { "do_reserved", 0x00000000001014a0, 120 },
    { "vga_printnum", 0x0000000000100fa0, 187 },
    { "alloc_dir_page", 0x0000000000102180, 227 },
    { "alloc_page", 0x0000000000102270, 20 },
    { "do_general_protection_fau", 0x00000000001013b0, 26 },
    { "isdigit", 0x0000000000101f90, 13 },
    { "_set_32e_gdt", 0x0000000000102380, 21 },
    { "kprintf", 0x0000000000100ad0, 149 },
    { "do_single_step", 0x00000000001011d0, 24 },
    { "do_div_by_zero", 0x00000000001011b0, 30 },
    { "setup_gate", 0x0000000000102400, 1337 },
    { "do_invalid_task_state_seg", 0x0000000000101350, 26 },
    { "ansi_escape", 0x0000000000100ba0, 415 },
    { "kmain", 0x00000000001000c0, 141 },
    { "do_coprocessor_segment_ov", 0x0000000000101330, 24 },
    { "clear_pagedir", 0x0000000000102970, 34 },
    { "do_overflow", 0x0000000000101230, 24 },
    { "strlen", 0x0000000000101bb0, 34 },
    { "no_cpuid", 0x0000000000102360, 2 },
    { "vga_print", 0x0000000000100f60, 53 },
    { "get_user_page_dir", 0x00000000001020b0, 55 },
    { "put_char", 0x0000000000102290, 39 },
    { "vga_clear", 0x0000000000100b70, 33 },
    { "disable_irq", 0x0000000000101670, 67 },
    { "free", 0x0000000000101b60, 76 },
    {"EOS", 0xFFFFFFFFFFFFFFFF, 0x0}
};
