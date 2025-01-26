/****************************************************************
* 1.5.4 Word Counting                                           *
* The fourth in our series of useful programs counts lines,     *
* words, and characters, with the loose definition that a word  *
* is any sequence of characters that does not contain a blank,  *
* tab or newline. This is a bare-bones version                  *
* of the UNIX program wc.                                       *
****************************************************************/

#include <stdio.h>

#define IN 1    // Inside a word
#define OUT 0   // Outside a word

int main()
{
    int c, nl, nw, nc, STATE = OUT;
    nl = nw = nc = 0;
    
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == '\n' || c == ' ' || c == '\t' )
            STATE = OUT;
        else if (STATE == OUT)
        {
            STATE = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}