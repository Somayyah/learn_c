// Global Section - Declares entry point
.global _start
.intel_syntax noprefix

// TEXT Section - Holds the code to be excuted
.section .text
_start:	

	// sys_write call	
	mov rax, 1
	mov rdi, 1	
	lea rsi, [hello_world]
	mov rdx, 14 
	syscall
	
	// sys_exit call to exit from the program
	mov rax, 60
	mov rdi, 0
	syscall

// DATA Section - For initialized variables
.section .data
hello_world:
	.asciz "New text"

// BSS Section - For uninitialized variables
.section .bss 
