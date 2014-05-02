#include <stdio.h>

main()
{
    int c, blanks, tabs, newlines;
    blanks = tabs = newlines = 0;

    while((c = getchar()) != EOF) {
        if( c == '\n') {
            ++newlines;
        }

        if( c == '\t') {
            ++tabs;
        }

        if( c == ' ') {
            ++blanks;
        }
    }

    printf("Blanks: %d\tTabs: %d\tNewlines: %d\n", blanks, tabs, newlines);
}
