//Prints variables in different number systems using printf and format strings.

#include <stdio.h>
#include <string.h>

int main() 
{   
    char string[10];
    int A = -73;
    unsigned int B = 31337; 
    strcpy(string, "sample");

    //Example of printing with different format string
    printf("[A] Dec: %d, Hex: %x, Unsigned: %u\n", A, A, A);
    printf("[B] Dec: %d, Hex: %x, Unsigned: %u\n", B, B, B);
    //Numbers can be added to designate the number of digits
    printf("[field width on B] 3: '%3u', 10: '%10u', '%08u'\n", B, B, B); 
    printf("[string] %s  Address %08x\n", string, string);

    //Example of unary address operator (dereferencing) and a %x format string
    printf("variable A is at address: %08x\n", &A);
}

//%d Decimal
//%u Unsigned decimal
//%x Hexadecimal
//&s String
//%n Writes number of bytes written in memory address
