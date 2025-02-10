/********************************************************************
 * Exercise 1-13. Write a program to print a histogram of the lengths*
 * of words in its input. It is easy to draw the histogram with the  *
 * bars horizontal; a vertical orientation is more challenging.      *
 *********************************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c = 0;
  int histogram[12] = {0};  // This ensures all elements are 0
  int counter = 0;
  int state = OUT;
  c = getchar();

  while (c = getchar()) != EOF) {

      if (c == ' ' || c == '\n' || c == '\t') {
        if (state == OUT) continue;
        state = OUT;
        if (counter > 0 && counter < 11) ++histogram[counter];
        if (counter >= 11) ++histogram[11];
        counter = 0;
      }
      else 
      {
        state = IN;   
        ++counter;
      }

  }

  if (counter > 0) {  
    if (counter < 11) ++histogram[counter];
    else ++histogram[11];
  }
  
  for (int i = 0; i < 12; i++)
    printf("%d : %d\n", i, histogram[i]);
  return 0;
}
