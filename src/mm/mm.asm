global memcpy
global memset
global memsetw
memcpy:
    	push rbp
    	mov	rbp, rsp

    	push rsi
    	push rdi
    	push rcx

    	mov	rdi, [rbp + 8]
    	mov	rsi, [rbp + 12]
    	mov	rcx, [rbp + 16]
    .1:
    	cmp	rcx, 0
    	jz	.2

    	mov	al, [rsi]
    	inc	rsi

    	mov	byte [es:rdi], al
    	inc	edi

    	dec	rcx
    	jmp	.1
    .2:
    	mov	rax, [rbp + 8]

    	pop	rcx
    	pop	rdi
    	pop	rsi
    	mov	rsp, rbp
    	pop	rbp

    	ret
memset:
    	push rbp
    	mov	rbp, rsp

    	push rsi
    	push rdi
    	push rcx

    	mov	rdi, [rbp + 8]
    	mov	rdx, [rbp + 12]
    	mov	rcx, [rbp + 16]
    .1:
    	cmp	rcx, 0
    	jz	.2

    	mov	byte [rdi], dl
    	inc	rdi

    	dec	rcx
    	jmp	.1
    .2:

    	pop	rcx
    	pop	rdi
    	pop	rsi
    	mov	rsp, rbp
    	pop	rbp

    	ret
memsetw:
    	push	rbp
    	mov	rbp, rsp

    	push rsi
    	push rdi
    	push rcx

    	mov	rdi, [rbp + 8]
    	mov	rdx, [rbp + 12]
    	mov	rcx, [rbp + 16]
    .11:
    	cmp	rcx, 0
    	jz	.22

    	mov	word [rdi], dx
    	add	rdi,2

    	dec	rcx
    	jmp	.11
    .22:

    	pop	rcx
    	pop	rdi
    	pop	rsi
    	mov	rsp, rbp
    	pop	rbp

    	ret