/*
Modify the ELF file so the string is printed if the user enters wrong answer
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wrong # of arguments!\n");
        return 1;
    }
    if (strcmp(argv[1], "Hello") == 0)
        printf("Hello!\n");
    else printf("Try again!\n");
    return 0;
}