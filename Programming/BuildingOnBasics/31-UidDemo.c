// Prints both the real and effective id of a user.
// Shows that a file or program can effectively alter a user's id.

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("real uid: %d\n", getuid());
    printf("effective uid: %d\n", geteuid());
}
