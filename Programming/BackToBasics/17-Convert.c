// Uses command-line arguments to input and repeat a string n number of times.
// Shows that command-line arguments are input as strings but can be converted to others types with functions.
// Such as atoi() - ASCII to integer.

#include <stdio.h>
#include <stdlib.h>

void useage(char *programName)
{
    printf("Usage: %s <message> <# of lines to repeat>\n", programName);
    exit(1);
}

int main(int argc, char *argv[])
{
    int i, count;

    if (argc < 3) // If fewer than 3 arguments are used, display usage message and exit.
    {
        useage(argv[0]);
    }

    count = atoi(argv[2]); // Convert the 2nd argument into an integer.
    printf("Repeating long%d times...\n", count);

    for (i = 0; i < count; i++)
    {
        printf("%3d - %s\n", i, argv[1]); // Print the 1st arg.
    }
}
