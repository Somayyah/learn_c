# Print "Hello, World!" 5 times

.global _start
.intel_syntax noprefix

.section .text
_start:	
	jMP print
	# sys_exit call to exit from the program

exit_code:
	mov rax, 60
	mov rdi, 0
	syscall

print:
	# sys_write call	
	mov rax, 1
	mov rdi, 1	
	lea rsi, [hello_world]
	mov rdx, 14 
	syscall
	add byte ptr [counter], 1
	cmp byte ptr [counter], 4
	jle print
	jmp exit_code

.section .data
hello_world:
	.asciz "Hello, World!\n"
counter: .byte 0

.section .bss
