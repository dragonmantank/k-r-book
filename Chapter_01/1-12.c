#include <stdio.h>

#define IN  1
#define OUT 0

main()
{
    int c, prevC;
    prevC = EOF;

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\t') {
            if(prevC != ' ' && prevC != '\t') {
                putchar('\n');
            }
        } else {
            putchar(c);
        }
        prevC = c;
    }
}
