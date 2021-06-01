//Program that iterates across a char array and an int array.
//Shows they iterate a different number of bytes across in memory; as a char is one byte and an int is four.

#include <stdio.h>

int main(void)
{
    int i;

    char charArray[5] = {'a', 'b', 'c', 'd','e'};
    int intArray[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    char_pointer = charArray;
    int_pointer = intArray;

    for (i = 0; i < 5; i++)
    {
        //Iterate through the int array with the int_pointer.
        printf("[integer pointer] points to %p, which contains the integer %d\n", int_pointer, *int_pointer);
        int_pointer = int_pointer + 1;
    }

    for (i = 0; i < 5; i++)
    {
        //Iterate through the char array with the char_pointer.
        printf("[char pointer] points to %p, which contains the char '%c'\n", char_pointer, *char_pointer);
        char_pointer = char_pointer + 1;
    }
}

