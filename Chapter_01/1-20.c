#include <stdio.h>

#define MAXLINE 1024
#define TABSTOP 4

int readline(char line[], int maxline);
void detab(char line[]);
void copy(char to[], char from[]);

int main()
{
    char line[MAXLINE];

    while((readline(line, MAXLINE)) > 0) {
        printf("Detabbing\n");
        detab(line);
        printf("%s", line);
    }
}

void detab(char line[]) {
    char storage[MAXLINE];
    int i = 0, j = 0, j_stop = 0;

    while(line[i] != '\0') {
        if (line[i] == '\t') {
            for (j_stop = j + TABSTOP; j < j_stop; j++) {
                storage[j] = ' ';
            }
        } else {
            storage[j] = line[i];
            j++;
        }
        
        i++;
    }
    storage[j] = '\0';
    copy(line, storage);
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