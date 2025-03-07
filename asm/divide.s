.intel_syntax noprefix
.global _start
    
# For each operation, print the quotient and remainder.

.section .data
iterator:   .byte   0
buffer:     .word   0
newline:    .byte   10      # ascii value for a newline
sign:       .byte    0

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
    mov     eax, -32768
    mov     bx, 256
    idiv    bx
    mov     byte ptr [sign], 45
    neg     eax		# eax = 128
	cwd
    call    store_number_on_stack
    ret
    
ex5:
    # 1000000 / 1234 (Dividend requires 20 bits) 32 bits unsigned, EDX:EAX ÷ r/m32 = EAX := Quotient, EDX := Remainder
	# Answer is 810
    mov     eax, 1000000   
    mov     edx, 0
    mov     ebx, 1234
    div     ebx 
    call    store_number_on_stack
    ret
	
ex6:
    # -2147483648 / 65536
    ret
    
ex7:
    # 100000000000 / 987654
    ret
    
ex8:
    # -9223372036854775808 / 4294967296
    ret

store_number_on_stack:   
	test	eax, 0xFFFF0000
	jz		store_16_bit_on_stack
	jmp		store_32_bit_on_stack

store_16_bit_on_stack:
	xor     ah, ah
    mov     bl, 10
    div     bl
    add     ah, 0x30
	movzx 	ecx, ah    
	push 	cx 
    add     byte ptr [iterator], 1
    cmp     al, 0
    jne     store_16_bit_on_stack
	jmp		after_storing
	ret

store_32_bit_on_stack: 
	# EDX:EAX ÷ r/m32 = EAX := Quotient, EDX := Remainder
	xor     edx, edx
    mov     ecx, 10
    div     ecx
    add     ax, 0x30
	movzx 	ecx, ah    
	push 	cx 
    add     byte ptr [iterator], 1
    cmp     al, 0
    jne     store_32_bit_on_stack
	jmp		after_storing
	ret

after_storing:
    cmp     byte ptr [sign], 45
    je      push_sign
    jmp     print_int
    ret

push_sign:
    xor     cx, cx
    mov     cl, byte ptr [sign] 
    add     byte ptr [iterator], 1
    push    cx
    jmp     print_int

print_int:
    pop     word ptr [buffer]
    mov     rdi, 1  # stdout
    mov     rax, 1  # sys_write syscall number
    lea     rsi, [buffer]  # Address of res
    mov     rdx, 2  # Write 2 byte
    syscall
    sub     byte ptr [iterator], 1
    cmp     byte ptr [iterator], 0
    jne     print_int
    ret

cleanup:
    mov     byte ptr [iterator], 0
    mov     byte ptr [sign], 0
    mov     word ptr [buffer], 0
    mov     rdi, 1
    mov     rax, 1  # sys_write syscall number
    lea     rsi, [newline]  # Address of newline
    mov     rdx, 1  # Write 1 byte
    syscall
	xor     rax, rax
    xor     rbx, rbx
    xor     rcx, rcx
    ret

exit_code:
    # sys_exit
    mov     rax, 60  # sys_exit syscall number
    mov     rdi, 0  # Exit code 0
    syscall
