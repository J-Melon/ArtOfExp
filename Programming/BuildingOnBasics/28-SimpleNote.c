//Writes a string from a command-line argument to a tmp file.
//Shows how file access operates in C.
//This uses file descriptors which are a set of low-level I/O functions.
//Filestream can also be used; higher-level I/O functions - easier to use (arguably) but are less direct.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> //Defines the flags used w/ open() - used to set access mode (read/write etc.)
#include <sys/stat.h> //^^
#include <unistd.h> //For write() and close()

void usage(char *progName, char *filename)
{
    printf("Usage: %s <data to add to %s>\n", progName, filename);
    exit(0);
}

void fatal(char *); //A function for fatal errors
void *ecMalloc(unsigned int); //An error-checked malloc() wrapper

int main(int argc, char *argv[])
{
    int fd; //File descriptor
    char *buffer, *datafile;

    buffer = (char *) ecMalloc(100);
    datafile = (char *) ecMalloc(20);
    strcpy(datafile, "/tmp/notes");

    if (argc < 2) //If there aren't command-line arguments
    {
        usage(argv[0], datafile); //Display usage message and exit
    }
    
    strcpy(buffer, argv[1]); //Copy into buffer

    printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    strcat(buffer, "\n"); //Add a newline onto the end

    //Opening file
    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1) //-1 denotes an exception
    {
        fatal("in main() while opening file");
    }

    printf("[DEBUG] file descriptor is %d\n", fd);

    //Writing data
    if (write(fd, buffer, strlen(buffer)) == -1)
    {
        fatal("in main() while writing buffer to file");
    }

    //Closing file
    if (close(fd) == -1)
    {
        fatal("in main() while closing file");
    }

    printf("Note has been saved.\n");
    free(buffer);
    free(datafile);
}

//A function to display an error message and then exit
void fatal(char *message)
{
    char errorMessage[100];

    strcpy(errorMessage, "[!!] Fatal Error ");
    strncat(errorMessage, message, 83);
    perror(errorMessage); //Print error function, prints additional information for an error.
    exit(-1);
}

//An error-checked malloc() wrapper function
void *ecMalloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    {
        fatal("in ecMalloc() on memory allocation");
    }
    return ptr;
}

//open() access mode flags
//O_RDONLY Open file for read-only access
//O_WRONLY Open file for write-only access
//O_APPEND Write data at the end of the file
//O_TRUNC If the file already exists, truncate (shorten) the file to 0 length
//O_CREAT Create the file if it doesn't exist
