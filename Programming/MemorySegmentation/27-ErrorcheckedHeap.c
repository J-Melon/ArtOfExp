//Allocates and deallocates memory for pointers on the heap.
//Shows that a function can be made to handle the error checking of the malloc() function.
//Therefore, it can be used in place of the standard malloc().
//As it is incorporated into the error-checking function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorcheckedMalloc(unsigned int); //Function prototype

int main(int argc, char *argv[])
{
    char *charPtr; //A character pointer
    int *intPtr; //An integer pointer
    int memSize;

    if (argc < 2) //If there aren't command-line arguments 
    {
        memSize = 50; //Use 50 as the default value
    }
    else
    {
        memSize = atoi(argv[1]);
    }

    printf("\t[+] allocating %d bytes of memory on the heap for charPtr\n", memSize);
    charPtr = (char *) errorcheckedMalloc(memSize); //Allocated heap memory
    //Returns void pointer cast to char

    strcpy(charPtr, "This is memory is located on the heap.");
    printf("charPtr (%p) --> '%s'\n", charPtr, charPtr);
    printf("\t[+] allocating 12 bytes of memory on the heap for intPtr\n");
    intPtr = (int *) errorcheckedMalloc(12); //Allocated heap memory again

    *intPtr = 31337; //Put the value of 31337 where intPtr is pointing.
    printf("intPtr (%p) --> %d\n", intPtr, *intPtr);

    printf("\t[-] freeing charPtr's heap memory...\n");
    free(charPtr); //Freeing heap memory

    printf("\t[+] allocating another 15 bytes for charPtr\n");
    charPtr = (char *) errorcheckedMalloc(15); //Allocating more heap memory
    
    strcpy(charPtr, "new memory");
    printf("char_ptr (%p) --> '%s'\n", charPtr, charPtr);

    printf("\t[-] freeing intPtr's heap memory...\n");
    free(intPtr); //Freeing heap memory
    printf("\t[-] freeing charPtr's heap memory...\n");
    free(charPtr); //Freeing the other block of heap memory
}

//An error-checked malloc() function
void *errorcheckedMalloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: could not allocate heap memory.\n");
        exit(-1);
    }

    return ptr;
}
