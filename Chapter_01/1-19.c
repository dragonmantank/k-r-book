#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int readline(char line[], int maxline);
void reverse(char line[]);
void copy(char to[], char from[]);

int main()
{
    int len, c;
    char line[MAXLINE];

    while ((readline(line, MAXLINE)) > 0) {
        reverse(line);

        printf("%s", line);
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

void reverse(char line[])
{
    int i = 0;
    int j = 0;
    int len = 0;
    char reverse[MAXLINE];

    copy(reverse, line);

    while (line[i] != '\0' && line[i] != '\n' && line[i] != '\r') {
        i++;
    }
    len = i;

    for(j = 0; j <= len; j++) {
        i--;
        line[j] = reverse[i];
        
    }

    j++; line[j] = '\n';
    j++; line[j] = '\0';
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}