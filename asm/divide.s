.intel_syntax noprefix
.global _start
    
# For each operation, print the quotient

.section .text
_start:
    call    ex1
    call    ex2
    call    ex3
    call    ex4
    call    ex5
    call    ex6
    call    ex7
    call    ex8
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
    mov     byte ptr [sign], 45
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
	xor     ah, ah
    mov     bl, 10
    div     bl
    add     ah, 0x30
	movzx 	ecx, ah    
	push 	cx 
    add     byte ptr [iterator], 1
    cmp     al, 0
    jne     store_8_bit_on_stack
	call	print_sign
	jmp		print_int
	ret

store_16_bit_on_stack: 
	xor     edx, edx
    mov     ecx, 10
    div     ecx
    add     dx, 0x30
	push 	dx 
    add     byte ptr [iterator], 1
    cmp     eax, 0
    jne     store_16_bit_on_stack
	call	print_sign
	jmp		print_int
	ret	

print_sign:
	mov     rdi, 1
    mov     rax, 1
    lea     rsi, [sign]  
    mov     rdx, 2
    syscall
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
	
print_newline:
    mov     rdi, 1
    mov     rax, 1
    lea     rsi, [newline]  
    mov     rdx, 1
    syscall
	ret

exit_code:
    mov     rax, 60
    mov     rdi, 0 
    syscall

.section .data
iterator:   .byte   0		# How many digits to print
buffer:     .word   0
newline:    .byte   10      # ascii value for a newline
sign:       .byte   43   # for sign '+'

