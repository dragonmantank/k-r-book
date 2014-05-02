#include <stdio.h>

#define MAX_WORD_LENGTH 45

main()
{
    int c, currentLength, i, j;
    int wordLengthFrequencies[MAX_WORD_LENGTH];
    for(i = 0; i <= MAX_WORD_LENGTH; ++i) {
        wordLengthFrequencies[i] = 0;
    }

    printf("Enter a string of words to compute the word length frequency. Hit CTRL+D to compute\n");
    currentLength = 0;
    while((c = getchar()) != EOF) {
        if(c != ' ' && c != '\t' && c != '\n') {
            ++currentLength;
        } else {
            ++wordLengthFrequencies[currentLength];
            currentLength = 0;
        }
    }
    ++wordLengthFrequencies[currentLength];

    printf("Length Histogram of inputted words\n");
    printf("================================================================================\n");
    for(i = 1; i <= MAX_WORD_LENGTH; ++i) {
        int frequency = wordLengthFrequencies[i];
        if(frequency > 0) {
            printf("%d: ", i);
            for(j = 0; j < frequency; ++j) {
                putchar('#');
            }
            putchar('\n');
        }
    }
}
