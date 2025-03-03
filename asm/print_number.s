# Focus on printing numbers regardless of size and sign

.intel_syntax noprefix
.global _start

.section .text
_start:
    
    mov     rax, 1
    call    print_int
    # Exit the program
    mov     rax, 60                  # syscall: exit
    xor     rdi, rdi                 # status: 0
    syscall

print_int:

.section .data
buffer      .byte   0