// Prints random values; first from 0 to RAND_MAX, then from 0 to 20 using the modulus operator.
// Shows how the rand() function is not absolutely random.
// A random seed has to be used to generate a random number.
// If the seed automatically changes but does so in a pattern; a pseudo-random number is generated.
// This is predictable when you can predict the rand() function.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
    printf("RAND_MAX is %u\n", RAND_MAX);
    srand(time(0));

    printf("random values from 0 to RAND_MAX\n");
    for (i = 0; i < 8; i++) { printf("%d\n", rand()); }

    printf("random values from 1 to 20\n");
    for (i = 0; i < 8; i++) { printf("%d\n", (rand() % 20) + 1); }
}

