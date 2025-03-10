.intel_syntax noprefix
.global _start
    
# For each operation, print the quotient

.section .data
iterator:   .byte   1		# How many digits to print
buffer:     .word   0
newline:    .byte   10      # ascii value for a newline
sign:       .word   43

.section .bss

.section .text
_start:
    call    ex1
    call    cleanup
    call    ex2
    call    cleanup
    call    ex3
    call    cleanup
    call    ex4
    call    cleanup
    call    ex5
    call    cleanup
    call    ex6
    call    cleanup
    call    ex7
    call    cleanup
    call    ex8
    call    cleanup
    jmp     exit_code

ex1:
    # 200 / 5 ( 0 -> 255 ) 8 bit unsigned, AX ÷ r/m8 = AL := Quotient, AH := Remainder
    mov     ax, 200
    mov     bl, 5   
    div     bl
    call    store_number_on_stack
    ret

ex2:
    # -100 / 25 ( -127 -> 127 ) 8 bit signed, AX ÷ r/m8 = AL := Quotient, AH := Remainder
    mov     ax, -100
    mov     bl, 25
    idiv    bl  
    mov     word ptr [sign], 45
    neg     al
    call    store_number_on_stack
    ret

ex3:
    # 5000 / 100 ( −32,768 -> +32,767 ) 16 bit signed, DX:AX ÷ r/m16 = AX := Quotient, DX := Reminder
    mov     eax, 5000
    cwd
    mov     bx, 100
    div     bx
    call    store_number_on_stack
    ret
    
ex4:
    # -32768 / 256 ( −32,768 -> +32,767 ) 16 bit signed, DX:AX ÷ r/m16 = AX := Quotient, DX := Reminder
    mov     ax, -32768
	cwd
    mov     bx, 256
    idiv    bx
    mov     byte ptr [sign], 45
    neg     ax		# ax = 128
	cwd
    call    store_number_on_stack
    ret
    
ex5:
    # 1000000 / 1234 (Dividend requires 20 bits) 32 bits unsigned, EDX:EAX ÷ r/m32 = EAX := Quotient, EDX := Remainder
	# Answer is 810 = 0x32a
    mov     eax, 1000000   
    mov     edx, 0
    mov     ebx, 1234
    div     ebx 
    call    store_number_on_stack
    ret
	
ex6:
    # -2147483648 / 65536 Signed divide EDX:EAX ÷ r/m32 = EAX := Quotient, EDX := Remainder
	mov		eax,-2147483648
	cdq
	mov	    ebx, 65536
	idiv	ebx
	mov     byte ptr [sign], 45
	neg		eax
	call	store_number_on_stack
    ret
    
ex7:
    # 100000000000 / 987654 Unsigned divide RDX:RAX ÷ r/m64 = RAX := Quotient, RDX := Remainder
	# 101250 = 18B82
	mov		rax, 100000000000
	xor		rdx, RDX
	mov		rbx, 987654
	div		rbx
	call 	store_number_on_stack
    ret
    
ex8:
    # -9223372036854775808 / 4294967296 signed divide RDX:RAX ÷ r/m64 = RAX := Quotient, RDX := Remainder
	mov		rax, -9223372036854775808
	cdq
	mov		rbx, 4294967296
	div		rbx
	mov     byte ptr [sign], 45
	neg		rax
	call 	store_number_on_stack
    ret

store_number_on_stack:   
	test  	eax, 0xFFFFFF00
	jz		store_8_bit_on_stack
	jmp		store_16_bit_on_stack

store_8_bit_on_stack:
	# DX:AX ÷ r/m16 = AX := Quotient, DX := Remainder	
	xor     ah, ah
    mov     bl, 10
    div     bl
    add     ah, 0x30
	movzx 	ecx, ah    
	push 	cx 
    add     byte ptr [iterator], 1
    cmp     al, 0
    jne     store_8_bit_on_stack
	jmp		after_storing
	ret

store_16_bit_on_stack: 
	# EDX:EAX ÷ r/m32 = EAX := Quotient, EDX := Remainder
	xor     edx, edx
    mov     ecx, 10
    div     ecx
    add     dx, 0x30
	push 	dx 
    add     byte ptr [iterator], 1
    cmp     eax, 0
    jne     store_16_bit_on_stack
	jmp		after_storing
	ret
	
after_storing:
    call	push_sign
    call    print_int
	call	print_newline
    ret

push_sign:
    push	word ptr [sign] 
    ret

print_int:
    pop     word ptr [buffer]
    mov     rdi, 1
    mov     rax, 1
    lea     rsi, [buffer]
    mov     rdx, 2
    syscall
    sub     byte ptr [iterator], 1
    cmp     byte ptr [iterator], 0
    jne     print_int
    ret

print_newline:
    mov     rdi, 1
    mov     rax, 1
    lea     rsi, [newline]  
    mov     rdx, 1
    syscall

cleanup:
    mov     byte ptr [iterator], 1
    mov     byte ptr [sign], 0
    mov     word ptr [buffer], 0
	xor     rax, rax
    xor     rbx, rbx
    xor     rcx, rcx
    ret

exit_code:
    mov     rax, 60
    mov     rdi, 0 
    syscall
