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

is_negative:

print_int:

.section .data
buffer:     .byte   0
sign:		.byte	0
num1:   .byte   42              # 8-bit positive number
num2:   .byte   -42             # 8-bit negative number
num3:   .word   12345           # 16-bit positive number
num4:   .word   -12345          # 16-bit negative number
num5:   .long   987654321       # 32-bit positive number
num6:   .long   -23456789       # 32-bit negative number
num7:   .quad   1234567890      # 64-bit positive number
num8:   .quad   -12345678901234 # 64-bit negative number