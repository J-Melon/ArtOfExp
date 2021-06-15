// Uses pointer shenanigans to form different string outputs. 

#include <stdio.h>
#include <string.h>

int main()
{
    char str_a[20];
    char *pointer; // Pointer for string array
    char *pointer2;

    strcpy(str_a, "Hello world\n");
    pointer = str_a; // Sets pointer to first array
    printf(pointer);

    pointer2 = pointer + 2; // Sets the second pointer 2 bytes further in the address memory
    printf(pointer2);
    strcpy(pointer2, "y you guys!\n"); // Copy string to new address
    printf(pointer);
}
