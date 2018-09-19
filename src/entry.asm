
;进入C，这个时候是已经启动64位了
global s_kernel_64_entry
extern multiboot
extern multiboot_magic
bits 64
s_kernel_64_entry:
        mov esp,0x10000
        extern kmain

        call kmain
        jmp $