# Focus on printing numbers regardless of size and sign

.intel_syntax noprefix

.section .data
num1:   	.byte   42
num2:   	.byte   -42
num3:   	.word   12345
num4:   	.word   -12345
num5:   	.long   987654321
num6:   	.long   -23456789
num7:   	.quad   1234567890
num8:   	.quad   -12345678901234
iterator:   .byte   0		# How many digits to print
buffer:     .word   0
newline:    .byte   10      # ascii value for a newline
sign:       .byte   43   # for sign '+'

.global _start

.section .text
_start:
    
    mov     rax, 60 
    xor     rdi, rdi
    syscall

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