// Program that iterates across a char array and an int array.
// Shows that to use a pointer with a different data type, it should be cast to that type.

#include <stdio.h>

int main(void)
{
    int i;

    char charArray[5] = {'a', 'b', 'c', 'd','e'};
    int intArray[5] = {1, 2, 3, 4, 5};

    char *charPointer;
    int *intPointer;

    charPointer = (char *) intArray; // Typecast into the pointer's data type.
    intPointer = (int *) charArray;

    for (i = 0; i < 5; i++)
    {
        // Iterate through the int array with the int pointer.
        printf("[integer pointer] points to %p, which contains the char '%c'\n", intPointer, *intPointer);
        intPointer = (int *) ((char *) intPointer + 1);
    }

    for (i = 0; i < 5; i++)
    {
        // Iterate through the char array with the char pointer.
        printf("[char pointer] points to %p, which contains the integer %d\n", charPointer, *charPointer);
        charPointer = (char *) ((int *) charPointer + 1);
    }
}

