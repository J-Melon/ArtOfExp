// Shows that pointers can be used to point to functions.

#include <stdio.h>

int func1()
{
    printf("This is function 1\n");
    return 1;
}

int func2()
{
    printf("This is function 2\n");
    return 2;
}

int main(void)
{
    int value;
    int (*functionPtr) (); 

    functionPtr = func1;
    printf("functionPtr points to %p\n", functionPtr);
    value = functionPtr();
    printf("value returned was %d\n", value);

    functionPtr = func2;
    printf("functionPtr points to %p\n", functionPtr);
    value = functionPtr();
    printf("value returned was %d\n", value);
}
