.intel_syntax noprefix
.global _start

.section .text
_start:

    # Calculate 1 + 1
    mov eax, 1 
    add eax, 1  # eax = 2
    add eax, 0x30  # Convert 2 → ASCII '2'
    mov [res], al  # Store ASCII '2' in res

    # sys_write (write '2' to stdout)
    mov rdi, 1  # stdout
    mov rax, 1  # sys_write syscall number
    lea rsi, [res]  # Address of res
    mov rdx, 1  # Write 1 byte
    syscall

    # sys_write (write '\n' to stdout)
    mov rdi, 1  # stdout
    mov rax, 1  # sys_write syscall number
    lea rsi, [newline]  # Address of newline
    mov rdx, 1  # Write 1 byte
    syscall

    # sys_exit
    mov rax, 60  # sys_exit syscall number
    mov rdi, 0  # Exit code 0
    syscall

.section .data
    res: .byte 0  # Properly initialized memory
    newline: .byte 10 # ascii value for a newline
