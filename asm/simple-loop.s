# Print "Hello, World!" 5 times

.global _start
.intel_syntax noprefix

.section .text
_start:	

	# sys_write call	
	mov rax, 1
	mov rdi, 1	
	lea rsi, [hello_world]
	mov rdx, 14 
	syscall
	
	# sys_exit call to exit from the program
	mov rax, 60
	mov rdi, 0
	syscall

.loop:
    
.section .data
hello_world:
	.asciz "Hello, World!\n"

.section .bss 
