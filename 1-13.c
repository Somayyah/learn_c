/********************************************************************
 * Exercise 1-13. Write a program to print a histogram of the lengths*
 * of words in its input. It is easy to draw the histogram with the  *
 * bars horizontal; a vertical orientation is more challenging.      *
 *********************************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c, histogram[10], counter, STATE = IN;
  c = counter = 0;

  for (int i = 0; i < 10; i++) {
    histogram[i] = 0;
  }

  while ((c = getchar()) != EOF) {

    if (STATE = IN) {
      if (c = ' ' || c == '' || c == '\t') {
        STATE = OUT;
        counter = 0;
        continue;
      }

      while ((c = getchar()) != ' ' && != '\t' && '\n') {
        if (c == EOF) break;
        ++counter;
      }
    }

    if (STATE = OUT) {

    }

    ++histogram[counter];
    counter = 0;
  }

  for (int i = 0; i < 10; i++)
    printf("%d : %d\n", i, histogram[i]);
  return 0;
}