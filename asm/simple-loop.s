.intel_syntax noprefix
.global _start

.section .text
_start:	
	jmp print

exit_code:
	# syscall to exit from the program
	mov rax, 60
	mov rdi, 0
	syscall

print:
	# sys_write call to print "hello, world!"
	mov rax, 1
	mov rdi, 1	
	lea rsi, [hello_world]
	mov rdx, 14 
	syscall
	add byte ptr [counter], 1
	cmp byte ptr [counter], 4	# Did we print hello_world 5 times yet?
	jle print					# If not print again
	jmp exit_code				# Exit from the code

.section .data
hello_world:
	.asciz "Hello, World!\n"
counter: .byte 0
