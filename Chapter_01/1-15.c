#include <stdio.h>

float fahr_to_celsius(int temp);

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f\t%6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + step;
    }
}

float fahr_to_celsius(int temp)
{
    return (5.0 / 9.0) * (temp-32.0);
}

