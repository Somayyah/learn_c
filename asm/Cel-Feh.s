# print Fahrenheit-Celsius table
# for fahr 0 20 to 300 
# cel =  (5.0/9.0) * (fahr-32) 

.intel_syntax noprefix
.global _start

.section .text
_start:
    
    # sys_write call to print "C    :   F"
	mov     rax, 1
	mov     rdi, 1	
	lea     rsi, [header]
	mov     rdx, 10
	syscall
    # cmp     byte ptr [fahr], 300
    # jle     convert
    jmp convert

convert:
    
    # Print a Fahr and Cel for 0
    mov     ax, 0                       # fahr = 0
    sub     ax, 32                      # al = fahr - 32 = 0 - 32 = -32
    mov     bx, 5                       # to multiply by 5
    imul    bx                          # DX:AX = (5.0) * bx
    cwd                                 # sign extention AX into DX:AX
    mov     cx, 9                       # to devide AX by 9
    idiv    cx                          # DX:AX = AX / 9 ; quotant in AX, reminder in DX
    mov     [res], ax                   # store quotant in res, will deal with the reminder later
    jmp     print_number

print_number:
    idiv    ax                          # DX now should contain first digit
    add     dx, 0x30                    # Convert digit to ascii
    mov     [buffer], dx                # buffer now has the digit as ascii

    # sys_write
    mov     rdi, 1                      
    mov     rax, 1                      
    lea     rsi, [buffer]                
    mov     rdx, 1                      
    syscall

    cmp     ax, 0
    jne     print_number
    jmp     exit

exit:
    # sys_exit call to exit from the program
	mov rax, 60
	mov rdi, 0
	syscall

.section .data
    header:     .asciz  "C   :   F\n"
    res:        .word   0                 # Properly initialized memory
    newline:    .byte   10                # ascii value for a newline
    fahr:       .byte   0                 
    buffer:     .byte   0
