// Repeats a string n number of times to show the usage of scanf. 

#include <stdio.h>
#include <string.h>

int main(void)
{
    char message[13]; // Original array size causes buffer overflow
    int count, i;

    strcpy(message, "Hello world!");

    printf("Repeat how many times? ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("%3d - %s\n", i, message);
    }
}
