.intel_syntax noprefix
.global _start
    
# For each operation, print the quotient and remainder.

.section .text
_start:

    # ex1 : 200 / 5 ( 0 - 255 ) 8 bit unsigned
    mov     ax, 200
    mov     bl, 5   
    div     bl
    mov     byte ptr [ex1_q], al
    mov     byte ptr [ex1_r], ah
    jmp     store_number_on_stack

    # -100 / 25 ( )

    # 5000 / 100 ( )

    # -32768 / 256 () 

    # 1000000 / 1234

    # -2147483648 / 65536

    # 100000000000 / 987654

    # -9223372036854775808 / 4294967296

    # sys_exit
    mov     rax, 60  # sys_exit syscall number
    mov     rdi, 0  # Exit code 0
    syscall

store_number_on_stack:
    mov     bl, 10
    xor     dx, dx
    div     bl
    add     ah, 0x30
    push    ah
    cmp     al, 0
    jne     print_number

.section .data
ex1_q:      .byte   0
ex1_r:      .byte   0
.section .bss
