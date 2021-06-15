// Allocates and deallocates memory for pointers on the heap.
// Shows that after a certain size deallocated memory will be utilised.
// Instead of increasing the size of the heap, it will use that lower memory address.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *charPtr; // A character pointer
    int *intPtr; // An integer pointer
    int memSize;

    if (argc < 2) // If there aren't command-line arguments 
    {
        memSize = 50; // Use 50 as the default value
    }
    else
    {
        memSize = atoi(argv[1]);
    }

    printf("\t[+] allocating %d bytes of memory on the heap for charPtr\n", memSize);
    charPtr = (char *) malloc(memSize); // Allocated heap memory - returns void pointer cast to char

    // Error checking in case malloc() fails
    if(charPtr == NULL)
    {
        fprintf(stderr, "Error: could not allocate heap memory.\n"); // printf for std filestream
        exit(-1);
    }

    strcpy(charPtr, "This is memory is located on the heap.");
    printf("charPtr (%p) --> '%s'\n", charPtr, charPtr);

    printf("\t[+] allocating 12 bytes of memory on the heap for intPtr\n");
    intPtr = (int *) malloc(12); // Allocated heap memory again

    // Error checking in case malloc() fails
    if(charPtr == NULL)
    {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(-1);
    }

    *intPtr = 31337; // Put the value of 31337 where intPtr is pointing.
    printf("intPtr (%p) --> %d\n", intPtr, *intPtr);

    printf("\t[-] freeing charPtr's heap memory...\n");
    free(charPtr); // Freeing heap memory

    printf("\t[+] allocating another 15 bytes for charPtr\n");
    charPtr = (char *) malloc(15); // Allocating more heap memory

    // Error checking in case malloc() fails
    if(charPtr == NULL)
    {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(-1);
    }
    
    strcpy(charPtr, "new memory");
    printf("char_ptr (%p) --> '%s'\n", charPtr, charPtr);

    printf("\t[-] freeing intPtr's heap memory...\n");
    free(intPtr); // Freeing heap memory
    printf("\t[-] freeing charPtr's heap memory...\n");
    free(charPtr); // Freeing the other block of heap memory
}
