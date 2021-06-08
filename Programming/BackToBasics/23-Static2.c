//Prints a static variable in different functions with normal var reference, with added memory addresses.
//Shows that the two static variables have different memory addresses.
//Therefore, they are different, unconnected variables.

#include <stdio.h>

//An example function, with its own context.
void function()
{
    int var = 5;
    static int staticVar = 5; //Static variable initialisation

    printf("\t[in function] var @ %p = %d\n", &var, var);
    printf("\t[in function] staticVar @ %p = %d\n", &staticVar, staticVar);
    var++; //Add one to var
    staticVar++; //Add one to staticVar.
}

//The main function, with its own context.
int main(void)
{
    int i;
    int staticVar = 1337; //Another static, in a different context.

    for(i = 0; i < 5; i++)
    {
        printf("[in main] staticVar @ %p = %d\n", &staticVar, staticVar);
        function(); //Call the function
    }
}
