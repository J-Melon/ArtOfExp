//Program that should iterate across a character array and an integer array but does not compile.
//Due to incompatible pointer types (when warnings are active).
//Shows that pointers can be swapped with other data types causing unintended results.

#include <stdio.h>

int main(void)
{
    int i;

    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    int intArray[5] = {1, 2, 3, 4, 5};

    char *charPointer;
    int *intPointer;

    charPointer = intArray; //The charPointer and intPointer now point to incompatible data types.
    intPointer = charArray; 

    for (i = 0; i < 5; i++)
    {
        //Iterate through the int array with the intPointer.
        printf("[integer pointer] points to %p, which contains the char %c\n", intPointer, *intPointer);
        intPointer = intPointer + 1;
    }

    for (i = 0; i < 5; i++)
    {
        //Iterate through the char array with the charPointer.
        printf("[integer pointer] points to %p, which contains the integer %d\n", charPointer, *charPointer);
        intPointer = intPointer + 1;
    }
}
