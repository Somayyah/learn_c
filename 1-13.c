/********************************************************************
 * Exercise 1-13. Write a program to print a histogram of the lengths*
 * of words in its input. It is easy to draw the histogram with the  *
 * bars horizontal; a vertical orientation is more challenging.      *
 *********************************************************************/

#include <stdio.h>

int main() {

  int c = 0, histogram[12] = {0}, counter = 0;

  while ((c = getchar()) != EOF) {

      if (c == ' ' || c == '\n' || c == '\t') {
        if (counter > 0 && counter < 11) ++histogram[counter];
        if (counter >= 11) ++histogram[11]; // If word had more than 10 letters
        counter = 0;
      }
      else 
      {
        if (c == EOF) break;
        ++counter;
      }
  }

  for (int i = 0; i < 12; i++)
    printf("%d : %d\n", i, histogram[i]);
  return 0;
}
