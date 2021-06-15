//Prints the most useful bit flags for open() in base10 and binary.
//Shows that flags should be unique in bit-structure.
//Then, the OR operation equates to adding each flag together.
//This means that the program can interpret all the flags used out of one value.

#include <stdio.h>
#include <fcntl.h>

void displayFlags(char *, unsigned int);
void binaryPrint(unsigned int);

int main(int argc, char *argv[])
{
    displayFlags("O_RDONLY\t\t", O_RDONLY);
    displayFlags("O_WRONLY\t\t", O_WRONLY);
    displayFlags("O_RDWR\t\t\t", O_RDWR);
    printf("\n");
    displayFlags("O_APPEND\t\t", O_APPEND);
    displayFlags("O_TRUNC\t\t\t", O_TRUNC);
    displayFlags("O_CREAT\t\t\t", O_CREAT);
    printf("\n");
    displayFlags("O_WRONLY|O_APPEND|O_CREAT", O_WRONLY|O_APPEND|O_CREAT);
}

void displayFlags(char *label, unsigned int value)
{
    printf("%s\t: %d\t:", label, value);
    binaryPrint(value);
    printf("\n");
}

void binaryPrint(unsigned int value)
{
    unsigned int mask = 0xff000000; //Start with a mask for the highest byte.
    unsigned int shift = 256 * 256 * 256; //Start with a shift for the highest byte.
    unsigned int byte, byteIterator, bitIterator;

    for (byteIterator = 0; byteIterator < 4; byteIterator++)
    {
        byte = (value & mask) / shift; //Isolate each byte.
        printf(" ");

        //Print the byte's bits.
        for (bitIterator = 0; bitIterator < 8; bitIterator++)
        {
            if (byte & 0x80) //If highest bit is not 0
            {
                printf("1");
            }
            else
            {
                printf("0");
            }

            byte *= 2; //Move all bits to the left by 1.
        }

        mask /= 256; //Move the bits in mask right by 8.
        shift /= 256; //Move the bits in shift right by 8. 
    }
}
