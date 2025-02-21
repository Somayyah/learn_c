# print Fahrenheit-Celsius table
# for fahr 0 20 to 300 
# cel =  (5.0/9.0) * (fahr-32) 

.global _start
.intel_syntax noprefix

.section .text
_start:
    
    # sys_write call to print "C    :   F"

	mov     rax, 1
	mov     rdi, 1	
	lea     rsi, [header]
	mov     rdx, 10
	syscall

    # Print a Fahr and Cel for 0
    
    mov     al, 0           # fahr = 0
    sub     al, 32          # al = fahr - 32 = 0 - 32 = -32
    mov     bl, 5           # to multiply by 5
    imul    bl              # now AX = (5.0) * bl
    # This works however since fahr is up to 300 then we need to use IMUL as below:
    # F7 /5 IMUL r/m16 M Valid Valid DX:AX := AX ∗ r/m word.
    idiv    9               # eax = eax / 9
    mov     [res], eax      # store eax in res

    # sys_exit call to exit from the program
	mov rax, 60
	mov rdi, 0
	syscall

.section .data
    header:
        .asciz "C   :   F\n"
    res: .byte 0  # Properly initialized memory
    newline: .byte 10 # ascii value for a newline

.section .bss

# What to learn
#      Loops (iterating over Fahrenheit values from 0 to 300 in steps of 20) 
#      Performing integer arithmetic (multiplication, division, and subtraction)
#      Handling signed integers correctly (`idiv` and `cdq` for sign extension)
#      Printing formatted output (numbers and strings to stdout)
#      Converting integers to ASCII for display
#      Managing memory correctly (`.data` for initialized data, `.bss` for uninitialized)
#      Understanding integer vs floating-point calculations