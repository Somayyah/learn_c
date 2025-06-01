/* vars init */

int main()
{
    /*
        <+0>    f3 0f 1e fa     endbr64
        <+4>    55              push    rbp
        <+5>    48 89 e5        mov     rbp,rsp
    */
    int a = 0;
    /*
        <+8>    c7 45 fc 00 00 00 00      mov DWORD PTR [rbp-0x4], 0x0
    */
    char b = 'b';
    /*
        <+15>   c6 45 fb 62               mov BYTE PTR [rbp-0x1], 0x62
    */
    return 0;
    /*
        <+19>   b8 00 00 00 00          mov    eax,0x0
        <+24>   5d                      pop    rbp
        <+25>   c3                      ret
    */
}