// Uses command-line arguments to input and repeat a string n number of times.
// Shows that a C program without error checking command-line arguments will cause a memory violation.
// A segmentation fault - When a program tries to access a memory location outside the range of the program

#include <stdio.h>
#include <stdlib.h>

void usage(char *programName)
{
    printf("Usage: %s <message> <# of lines to repeat>\n", programName);
    exit(1);
}

int main(int argc, char *argv[])
{
    int i, count;

//   if (argc < 3) // If fewer than 3 arguments are used, display usage message and exit.
//   {
//       usage(argv[0]);
//   }

    count = atoi(argv[2]); // Convert the 2nd argument into an integer.
    printf("Repeating long%d times...\n", count);

    for (i = 0; i < count; i++)
    {
        printf("%3d - %s\n", i, argv[1]); // Print the 1st arg.
    }
}
