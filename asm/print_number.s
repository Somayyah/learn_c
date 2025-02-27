# Focus on printing numbers regardless of size and sign
.intel_syntax noprefix
.global _start

.section .text
_start:
    
    # Exit the program
    mov rax, 60                  # syscall: exit
    xor rdi, rdi                 # status: 0
    syscall

print_int:
    