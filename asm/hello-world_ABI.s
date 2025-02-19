// Global Section - Declares entry point
.global _start
.intel_syntax noprefix

// TEXT Section - Holds the code to be excuted
.section .text
_start:	


// DATA Section - For initialized variables
.section .data
hello_world:
	.asciz "New text"

// BSS Section - For uninitialized variables
.section .bss 
