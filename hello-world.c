#include <stdio.h>

int main()
{
    printf("Hello, World!");
}

/*
Dump of assembler code for function main:
   0x0000000000001149 <+0>:     f3 0f 1e fa             endbr64
                                    # prologue
   0x000000000000114d <+4>:     55                      push   %rbp
   0x000000000000114e <+5>:     48 89 e5                mov    %rsp,%rbp
                                    
   0x0000000000001151 <+8>:     48 8d 05 ac 0e 00 00    lea    0xeac(%rip),%rax        # 0x2004
   0x0000000000001158 <+15>:    48 89 c7                mov    %rax,%rdi
   0x000000000000115b <+18>:    b8 00 00 00 00          mov    $0x0,%eax
   0x0000000000001160 <+23>:    e8 eb fe ff ff          call   0x1050 <printf@plt>
   0x0000000000001165 <+28>:    b8 00 00 00 00          mov    $0x0,%eax
   0x000000000000116a <+33>:    5d                      pop    %rbp
   0x000000000000116b <+34>:    c3                      ret
End of assembler dump.
*/