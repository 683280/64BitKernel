

global entry_long_mode
extern no_cpuid
extern no_long_mode
extern setup_pae
extern setup_gdt
extern PML4T
extern pae_dir_ptr_tab
extern pae_page_dir
extern pae_page_tab

bits 32
entry_long_mode:

        call check_cupid

        mov eax, 0x80000000
        cpuid
        cmp eax, 0x80000001
        jb no_long_mode

        mov eax, 0x80000001
        cpuid
        test edx, 1 << 29
        jz no_long_mode

        jmp real_entry_long_mode

    check_cupid:
        pushfd
        pop eax

        mov ecx, eax

        xor eax, 1 << 21

        push eax
        popfd

        pushfd
        pop eax

        push ecx
        popfd

        xor eax, ecx
        jz no_cpuid
        ret

    real_entry_long_mode:
        ;setup PAE PAGING
        mov dword [PML4T],pae_dir_ptr_tab + 3
        mov dword [pae_dir_ptr_tab],pae_page_dir + 3
        mov dword [pae_page_dir],pae_page_tab + 3

        mov edi,pae_page_tab
        mov ebx, 0x00000003          ; Set the B-register to 0x00000003.
        mov ecx, 512                 ; Set the C-register to 512.
    .SetEntry:
        mov dword [edi], ebx         ; Set the uint32_t at the destination index to the B-register.
        add ebx, 0x1000              ; Add 0x1000 to the B-register.
        add edi, 8                   ; Add eight to the destination index.
        loop .SetEntry               ; Set the next entry.

        ;open pae
        mov eax,cr4
        mov eax, 10100000b
        mov cr4,eax
        ;
        mov eax,PML4T
        mov cr3,eax

        ;entry long mode
        mov ecx, 0xC0000080               ; Read from the EFER MSR.
        rdmsr

        or eax, 0x00000100                ; Set the LME bit.
        wrmsr
        ;open paging
        mov eax,cr0
        or eax,0x80000001
        mov cr0,eax

        ;load setup_gdt
        lgdt [GDT64.Pointer]         ; Load the 64-bit global descriptor table.
        ;jmp to 64 bit kernel
        jmp GDT64.Code : setup_64

        jmp $
    GDT64:                           ; Global Descriptor Table (64-bit).
        .Null: equ $ - GDT64         ; The null descriptor.
        dw 0xFFFF                    ; Limit (low).
        dw 0                         ; Base (low).
        db 0                         ; Base (middle)
        db 0                         ; Access.
        db 1                         ; Granularity.
        db 0                         ; Base (high).
        .Code: equ $ - GDT64         ; The code descriptor.
        dw 0xffff                         ; Limit (low).
        dw 0                         ; Base (low).
        db 0                         ; Base (middle)
        db 10011010b                 ; Access (exec/read).
        db 10101111b                 ; Granularity, 64 bits flag, limit19:16.
        db 0                         ; Base (high).
        .Data: equ $ - GDT64         ; The data descriptor.
        dw 0xffff                         ; Limit (low).
        dw 0                         ; Base (low).
        db 0                         ; Base (middle)
        db 10010010b                 ; Access (read/write).
        db 00000000b                 ; Granularity.
        db 0                         ; Base (high).
        .Pointer:                    ; The GDT-pointer.
        dw $ - GDT64 - 1             ; Limit.
        dq GDT64                     ; Base.
bits 64
    setup_64:
        ;setup cpu status
        cli
        mov ax,GDT64.Data
        mov ds,ax
        mov ss,ax
        mov gs,ax
        mov fs,ax
        mov es,ax
        mov ds,ax
        ;mov edi, 0xB8000              ; Set the destination index to 0xB8000.
        ;mov rax, 0x1F201F201F201F20   ; Set the A-register to 0x1F201F201F201F20.
        ;mov ecx, 500                  ; Set the C-register to 500.
        ;rep stosq                     ; Clear the screen.
        extern s_kernel_64_entry
        ;jmp to kernel in C
        jmp s_kernel_64_entry

global s_save
s_save:

		iret