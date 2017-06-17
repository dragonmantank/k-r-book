#include <stdio.h>

#define MAXLINE 1024
#define TABSTOP 4

int readline(char line[], int maxline);
void entab(char line[]);
void copy(char to[], char from[]);

int main()
{
    char line[MAXLINE];

    while((readline(line, MAXLINE)) > 0) {
        entab(line);
        printf("%s", line);
    }
}

void entab(char line[]) {
    char storage[MAXLINE];
    char previous_char;
    char space_count = 0;

    int i = 0, j = 0, i_stop = 0;

    while(line[i] != '\0') {
        if (line[i] == ' ') {
            int i_readahead = i + 1;
            for (i_stop = i + TABSTOP - 1; i_readahead < i_stop; i_readahead++) {
                if (line[i_readahead] != ' ') {
                    break;
                }
            }

            if (i_readahead == i_stop) {
                storage[j] = '\t';
                i = i_stop;
            } else {
                storage[j] = ' ';
            }
        } else {
            storage[j] = line[i];
        }

        j++;        
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