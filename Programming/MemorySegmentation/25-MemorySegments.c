//Prints memory addresses of variables issued into different memory segments.
//Stack has the highest memory address followed by heap, bss, and data.

//REMEMBER TO USE %p TO PRINT MEMORY ADDRESSES

#include <stdio.h>
#include <stdlib.h>

int globalVar;
int globalInitialisedVar = 5;

//This is just a demo function.
void function()
{
    int stackVar; //Notice this variable has the same name as the one in main().
    printf("the function's stackVar is at address %p\n", &stackVar);
}

int main(void)
{
    int stackVar; //Same name as the variables in function().
    static int staticInitialisedVar = 5;
    static int staticVar;
    int *heapVarPtr;

    heapVarPtr = (int *) malloc(4); //malloc is within standard library

    //These variables are in the data segment.
    printf("globalInitialisedVar is at address %p\n", &globalInitialisedVar);
    printf("staticInitialisedVar is at address %p\n\n", &staticInitialisedVar);

    //These variables are in the bss segment.
    printf("staticVar is at address %p\n", &staticVar);
    printf("globalVar is at address %p\n\n", &globalVar);

    //This variable is in the heap segment.
    printf("heapVar is at address %p\n\n", heapVarPtr);

    //These variables are in the stack segment.
    printf("stackVar is at address %p\n", &stackVar);
    function();
}
