#include <stdio.h>

main()
{
    printf("Typing in a character should result in a 1, immediatly doing a CTRL+D should result in 0\n");
    printf("%d\n", (getchar() != EOF));
}
