.intel_syntax noprefix
.global _start
    
# For each operation, print the quotient and remainder.

.section .text
_start:
    jmp     ex1

ex1:
    # 200 / 5 ( 0 - 255 ) 8 bit unsigned
    mov     ax, 200
    mov     bl, 5   
    div     bl
    jmp     store_number_on_stack

ex2:
    # -100 / 25 ( )
    mov rdi, 1  # stdout
    mov rax, 1  # sys_write syscall number
    lea rsi, [newline]  # Address of newline
    mov rdx, 1  # Write 1 byte
    syscall

ex3:
    # 5000 / 100 ( )
    
ex4:
    # -32768 / 256 () 
    
ex5:
    # 1000000 / 1234
    
ex6:
    # -2147483648 / 65536
    
ex7:
    # 100000000000 / 987654
    
ex8:
    # -9223372036854775808 / 4294967296
    
    jmp     exit_code

exit_code:
    # sys_exit
    mov     rax, 60  # sys_exit syscall number
    mov     rdi, 0  # Exit code 0
    syscall

store_number_on_stack:
    xor     ah, ah
    mov     bl, 10
    xor     dx, dx
    div     bl
    add     ah, 0x30
    push    ax
    add     byte ptr [iterator], 1
    cmp     al, 0
    je      print_int          
    jmp     store_number_on_stack 

print_int:
    pop     word ptr [buffer]
    mov     rdi, 1  # stdout
    mov     rax, 1  # sys_write syscall number
    lea     rsi, [buffer]  # Address of res
    mov     rdx, 2  # Write 2 byte
    syscall

    sub     byte ptr [iterator], 1
    cmp     byte ptr [iterator], 0
    jne     print_int
    jmp     ex2

.section .data
ex1_q:      .byte   0
ex1_r:      .byte   0
iterator:   .byte   0
buffer:     .word   0
newline: .byte 10 # ascii value for a newline

.section .bss
