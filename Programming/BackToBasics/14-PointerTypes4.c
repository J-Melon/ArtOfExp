// Program that iterates across a character array and an integer array.
// Shows that a void pointer can be used to iterate across both the character array and the integer array.
// As typecasting is used.

#include <stdio.h>

int main(void)
{
    int i;

    char charArray[5] = {'a', 'b', 'c', 'd','e'};
    int intArray[5] = {1, 2, 3, 4, 5};

    void *voidPointer;

    voidPointer = (void *) charArray;

    for (i = 0; i < 5; i++)
    {
        // Iterate through the char array with the void pointer.
        printf("[char pointer] points to %p, which contains the char '%c'\n",
                voidPointer, *((char *) voidPointer));
        voidPointer = (void *) ((char *) voidPointer + 1);
    }

    voidPointer = (void *) intArray;

    for (i = 0; i < 5; i++)
    {
        // Iterate through the integer array with the void pointer.
        printf("[integer pointer] points to %p, which contains the integer %d\n",
                voidPointer, *((int *) voidPointer));
        voidPointer = (void *) ((int *) voidPointer + 1);
    }
}

