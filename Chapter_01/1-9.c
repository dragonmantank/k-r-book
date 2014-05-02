#include <stdio.h>

main()
{
    int c, previousc;
    previousc = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ' && previousc == ' ') {
            // This space intentionally left blank
        } else {
            putchar(c);
        }
        previousc = c;
    }
}
