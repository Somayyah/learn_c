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
            case ' ' || '\t' || '\n': break; // This is wrong because the statement will be case 1 OR case 0 which is not what we want.
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