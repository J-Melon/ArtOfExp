// Prints hello world via strcpy'd array.

#include <stdio.h>
#include <string.h>

int main() 
{
    char str_a[20];

        strcpy(str_a, "Hello world!\n");
        printf(str_a); // Warning (potentially insecure) only relevant for user-controlled variables. 
                       // In case of injection.
}
