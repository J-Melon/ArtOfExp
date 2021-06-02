//Program prints value of i and j in different functions.
//Shows that local variables take precedence over global variables.
//Therefore, newly declared j can only be changed locally (does not affect the global variable).

#include <stdio.h>

int j = 42; //j is a global variable.

void func3()
{
    int i = 11, j = 999; //Here, j is a local variable of func3().
    printf("\t\t\t[in func3] i = %d, j = %d\n", i, j);
}

void func2()
{
    int i = 7;
    printf("\t\t[in func2] i = %d, j = %d\n", i, j);
    printf("\t\t[in func2] setting j = 1337\n");
    j = 1337; //Writing to j
    func3();
    printf("\t\t[back in func2] i = %d, j = %d\n", i, j);
}

void func1()
{
    int i = 5;
    printf("\t[in func1] i = %d, j = %d\n", i, j);
    func2();
    printf("\t[back in func1] i = %d, j = %d\n", i, j);
}

int main(void)
{
    int i = 3;
    printf("[in main] i = %d, j = %d\n", i, j); 
    func1();
    printf("[back in main] i = %d, j = %d\n", i, j); 

}
