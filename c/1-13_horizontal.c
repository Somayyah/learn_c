/********************************************************************
 * Exercise 1-13. Write a program to print a histogram of the lengths*
 * of words in its input. It is easy to draw the histogram with the  *
 * bars horizontal; a vertical orientation is more challenging.      *
 *********************************************************************/

#include <stdio.h>

int main() {

  int c = 0;
  int histogram[12] = {0};  
  int counter = 0;

  while ((c = getchar()) != EOF) {

      if (c == ' ' || c == '\n' || c == '\t') {
        if (counter > 0 && counter < 11) ++histogram[counter];
        if (counter >= 11) ++histogram[11];
        counter = 0;
      }
      else 
      {
        ++counter;
      }
  }

  if (counter > 0) {  
    if (counter < 11) ++histogram[counter];
    else ++histogram[11];
  }

  printf(" C : F\n");
  for (int i = 0; i < 12; i++)
  {
    if (histogram[i] > 0)
    {
      printf("%2d : ", i);
      for (int j = 0; j < histogram[i]; j++)
        putchar('*');
      putchar('\n');
    }
  }
  return 0;
}
