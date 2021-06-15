// Prints a static variable in different functions with a normal variable as a reference.
// Shows that static variables are like local variables but are only initalised once.
// So, they will keep their values between function calls instead of being re-initalised like normal.

#include <stdio.h>

// An example function, with its own context.
void function()
{
    int var = 5;
    static int staticVar = 5; // Static variable initialisation

    printf("\t[in function] var = %d\n", var);
    printf("\t[in function] staticVar = %d\n", staticVar);
    var++; // Add one to var
    staticVar++; // Add one to staticVar.
}

// The main function, with its own context.
int main(void)
{
    int i;
    int staticVar = 1337; // Another static, in a different context.

    for(i = 0; i < 5; i++)
    {
        printf("[in main] staticVar = %d\n", staticVar);
        function(); // Call the function
    }
}
