
ENTRY (s_kernel_entry)
SECTIONS{

    . = 0x100000;
    kern_start = .;
    .text ALIGN(0x1000):{
        *(.multiboot)
        *(.text)
    }

    .rodata ALIGN(0x1000):{
        *(.rodata)
    }

    .data ALIGN(0x1000):{
        *(.data)
    }

    .bss ALIGN(0x1000):{
        sbss = .;
        *(COMMON)
        *(.bss)
        *(.pte_desc)
        ebss = .;
    }

    kern_end = .;
}