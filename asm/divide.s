.intel_syntax noprefix
.global _start
    
# For each operation, print the quotient and remainder.

.section .text
_start:

    # sys_exit
    mov rax, 60  # sys_exit syscall number
    mov rdi, 0  # Exit code 0
    syscall

    # 200 / 5 
    # -100 / 25

    # 5000 / 100
    # -32768 / 256

    # 1000000 / 1234
    # -2147483648 / 65536

    # 100000000000 / 987654
    # -9223372036854775808 / 4294967296



.section .data

.section .bss
