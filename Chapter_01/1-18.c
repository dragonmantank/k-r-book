#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int readline(char line[], int maxline);

main()
{
    int len, c;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0) {
        len--;
        while (len >= 0 && (line[len] == ' ' || line[len] == '\t' || line[len] == '\r' || line[len] == '\n')) {
            --len;
        }

        if (len > 0) {
            ++len;
            line[len] = '\n';
            ++len;
            line[len] = '\0';
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
