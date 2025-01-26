/****************************************************************
 * Exercise 1-10. Write a program to copy its input to its      * 
 * output, replacing each tab by \t, each backspace by \\b, and * 
 * each backslash by \\. This makes tabs and backspaces visible * 
 * in an unambiguous way.                                       *
 ***************************************************************/

 #include <stdio.h>

 int main()
 {
    int c = 0; // To hold characters

    while ((c = getchar()) != EOF)
    {
        switch (c){
            case 8 :
                printf("%s", "\\b");
                break;
            case 9 :
                printf("%s", "\\t");
                break;
            case 92:
                printf("%s", "\\\\");
                break;
            default:
                putchar(c);
                break;
        }
    }
    return 0;
 }