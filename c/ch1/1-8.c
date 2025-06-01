// Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main() {
    int c;          
    int blanks = 0;
    int tabs = 0;
    int nl = 0;

    // Read characters until EOF
    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':  // Increment blank counter
                ++blanks;
                break;
            case '\t': // Increment tab counter
                ++tabs;
                break;
            case '\n': // Increment newline counter
                ++nl;
                break;
            default:
                // Do nothing
                break;
        }
    }

    printf("Blanks: %d\nTabs: %d\nNewLines: %d\n", blanks, tabs, nl);

    return 0;
}