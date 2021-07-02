// Writes a string from a command-line argument to a file in var.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // Defines the flags used w/ open() - used to set access mode (read/write etc.)
#include <sys/stat.h> // ^^
#include <unistd.h> // For write(), close(), and getuid()
#include "hacking.h"

void usage(char *progName, char *filename)
{
    printf("Usage: %s <data to add to %s>\n", progName, filename);
    exit(0);
}

void fatal(char *); // A function for fatal errors
void *ecMalloc(unsigned int); // An error-checked malloc() wrapper

int main(int argc, char *argv[])
{
    int userid, fd; // File descriptor
    char *buffer, *datafile;

    buffer = (char *) ecMalloc(100);
    datafile = (char *) ecMalloc(20);
    strcpy(datafile, "/var/notes");

    if (argc < 2) // If there aren't command-line arguments
    {
        usage(argv[0], datafile); // Display usage message and exit
    }
    
    strcpy(buffer, argv[1]); // Copy into buffer

    printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    // Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1) // -1 denotes an exception
    {
        fatal("in main() while opening file");
    }

    printf("[DEBUG] file descriptor is %d\n", fd);

    userid = getuid(); // Get real user id

    printf("\nUID:%d", userid); //Test-code

    // Writing data
    // Write user id before note data.
    if (write(fd, &userid, 4) == -1) { fatal("in main() while writing userid to file"); }
    write(fd, "\n", 1); // Terminate line.

    if (write(fd, buffer, strlen(buffer)) == -1) { fatal("in main() while writing buffer to file"); }
    write(fd, "\n", 1); // Terminate line.

    // Closing file
    if (close(fd) == -1) { fatal("in main() while closing file"); }

    printf("Note has been saved.\n");
    free(buffer);
    free(datafile);
}

// open() access mode flags
// O_RDONLY Open file for read-only access
// O_WRONLY Open file for write-only access
// O_APPEND Write data at the end of the file
// O_TRUNC If the file already exists, truncate (shorten) the file to 0 length
// O_CREAT Create the file if it doesn't exist

// Permission giving flags
// --To user (owner)--
// S_IRUSR Read.
// S_IWUSR Write.
// S_IXUSR Execute.
// --To group--
// S_IRGRP Read.
// S_IWGRP Write.
// S_IXGRP Execute.
// --Other (to anyone)--
// S_IROTH Read.
// S_IWOTH Write.
// S_IXOTH Execute.
