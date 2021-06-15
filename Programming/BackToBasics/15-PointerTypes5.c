// Program that iterates across a character array and an integer array using a long as a pointer.
// Shows that a pointer just needs to have a memory address to function.
// Therefore a pointer does not have to be cast as such, as seen here.

#include <stdio.h>

int main()
{
    int i;
    
    char char_array[5] = {'a', 'b', 'c','d', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    long hacky_nonpointer;

    hacky_nonpointer = (long) char_array;

    // Iterate through the char array with an unsigned integer
    for (i = 0; i < 5; i++)
    {
        printf("[hacky_pointer] points to %p, which contains the char '%c'\n", 
                hacky_nonpointer, *((char *) hacky_nonpointer));
        hacky_nonpointer = hacky_nonpointer + sizeof(char);
    }

    hacky_nonpointer = (long) int_array;
    
    // Iterate through the int array with an unsigned integer 
    for (i = 0; i < 5; i++)
    {
        printf("[hacky_nonpointer] points to %p, which contains the integer %d\n",
                hacky_nonpointer, *((int *) hacky_nonpointer));
        hacky_nonpointer += sizeof(int);
    }
}
