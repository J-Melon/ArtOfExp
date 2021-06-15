//Prints both the real and effective id of a user.
//Shows that a file or program can effectively alter the file permission of a user.

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("real uid: %d\n", getuid());
    printf("effective uid: %d\n", geteuid());
}
