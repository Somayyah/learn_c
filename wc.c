/****************************************************************
* 1.5.4 Word Counting                                           *
* The fourth in our series of useful programs counts lines,     *
* words, and characters, with the loose definition that a word  *
* is any sequence of characters that does not contain a blank,  *
* tab or newline. This is a bare-bones version                  *
* of the UNIX program wc.                                       *
 ***************************************************************/

 #include <stdio.h>

 int main()
 {
    int wc = 0;
    int c = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c){
            case ' ' : break;
            case '\t': break;
            case '\n': break;
            default:
                ++wc;
                while ((c = getchar()) != ' ' && c != '\t' && c != '\n' && c != EOF)
                ;
                break;
        }
    }
    printf("Number of words = %d\n", wc);
    return 0;
 }