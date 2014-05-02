#include <stdio.h>

main()
{
    int c, i, j;
    int letterFrequencies['z'];
    for(i = 'A'; i <= 'z'; ++i) {
        letterFrequencies[i] = 0;
    }

    printf("Enter a string of words to compute the letter frequency. Hit CTRL+D to compute\n");
    while((c = getchar()) != EOF) {
        if(c <= 'z' && c >= 'A') {
            ++letterFrequencies[c];
        }
    }

    printf("\n\nFrequency Histogram of inputted letters\n");
    printf("================================================================================\n");
    for(i = 'A'; i <= 'z'; ++i) {
        int frequency = letterFrequencies[i];
        if(frequency > 0) {
            putchar(i); printf(": ");
            for(j = 0; j < frequency; ++j) {
                putchar('#');
            }
            putchar('\n');
        }
    }
}
