#include <stdio.h>
#include <stdlib.h>

/*
read a character
while (charater is not end-of-file indicator)
output the character just read
read a character
*/
 
int main(void)
{
    for (int ch; (ch = getchar()) != EOF;) // read/print "abcde" from stdin
        printf("%c", ch);
 
    // Test reason for reaching EOF.
    if (feof(stdin)) // if failure caused by end-of-file condition
        puts("End of file reached");
    else if (ferror(stdin)) // if failure caused by some other error
    {
        perror("getchar()");
        fprintf(stderr, "getchar() failed in file %s at line # %d\n",
                __FILE__, __LINE__ - 9);
        exit(EXIT_FAILURE);
    }
 
    return EXIT_SUCCESS;
}