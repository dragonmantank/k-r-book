#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int readline(char line[], int maxline);

main()
{
    int len, c;
    int max;
    char line[MAXLINE];

    while ((len = readline(line, MAXLINE)) > 0) {
        if (line[len -1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                ++len;
            }

            if (c == '\n') {
                ++len;
            }
        }

        if (len > MINLINE) {
            printf("%s", line);
        }        
    }

    return 0;
}

int readline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}
