#include <stdio.h>
#define MAXLINE 10

int readline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len, c;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0) {
        if (line[len -1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                ++len;
            }

            if (c == '\n') {
                ++len;
            }
        }

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0) {
        printf("Longest line was %d characters long\n%s\n", max, longest);
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

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
