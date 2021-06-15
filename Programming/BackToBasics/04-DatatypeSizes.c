// Prints size of memory allocation of various types.
// Notice how long and long long sizes vary depending on platform.

#include <stdio.h>

int main()
{
    printf("The int data type is\t\t %td bytes\n", sizeof(int));
    printf("The 'unsigned int' data type is\t %td bytes\n", sizeof(unsigned int));
    printf("The 'short int' data type is\t %td bytes\n", sizeof(short int));
    printf("The 'long int' data type is\t %td bytes\n", sizeof(long int));   
    printf("The 'long long int' data type is %td bytes\n", sizeof(long long int));   
    printf("The 'float' data type is\t %td bytes\n", sizeof(float));   
    printf("The 'char' data type is\t\t %td bytes\n", sizeof(char));   
}
