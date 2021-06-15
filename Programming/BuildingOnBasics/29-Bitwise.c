//  Prints the results of OR, AND bitwise operations.
//  Shows that integers can be used to perform logic operations.

#include <stdio.h>

int main(void)
{
    int i, bitA, bitB;
    printf("bitwise OR operator |\n");

    for (i = 0; i < 4; i++)
    {
        bitA = (i & 2) / 2; //  Get the second bit
        bitB = (i & 1);
        printf("%d | %d = %d\n", bitA, bitB, bitA | bitB);
    }

    printf("\nbitwise AND operator &\n");

    for(i = 0; i < 4; i++)
    {
        bitA = (i & 2) / 2; //  Get the second bit
        bitB = (i & 1); //  Get the first bitB
        printf("%d & %d = %d\n", bitA, bitB, bitA & bitB);
    }
}
