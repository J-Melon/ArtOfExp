//This searches through the file notes in var

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hacking.h"

#define FILENAME "/var/notes"

int printNotes(int, int, char *); // Note printing function
int findUserNote(int, int); // Seek in file for a note for user
int searchNote(char *, char *); // Search for keyword function
void fatal(char *); // Fatal error handler

int main(int argc, char *argv[])
{
    int userID, printing = 1, fd; // File descriptor
    char searchString[100];

    if (argc > 1) { strcpy(searchString, argv[1]); } // If there is a search string, use it
    else { searchString[0] = 0; } // Otherwise search string is empty

    userID = getuid();
    fd = open(FILENAME, O_RDONLY); // Open the file for read-only access
    if (fd == -1) { fatal("in main() while opening file for reading"); }

    while(printing) { printing = printNotes(fd, userID, searchString); }
    printf("-------[ end of note data ]-------");
    close(fd);
}

// A function to print the notes for a given uid that matches an optimal search string
// Returns 0 at end of file, 1 if there are still more notes.
int printNotes(int fd, int uid, char *searchString)
{
    int noteLength;
    char byte = 0, noteBuffer[100];

    noteLength = findUserNote(fd, uid);
    if (noteLength == -1) { return 0; } // If end of file reached

    read(fd, noteBuffer, noteLength); // Read note data
    noteBuffer[noteLength] = 0; // Terminate the string
    
    if (searchNote(noteBuffer, searchString)) { printf(noteBuffer); }
    return 1;
}

// A function to find the next note for a given userID.
// Returns -1 if the end of the file is reached.
// Otherwise, it returns the length of the found note.
int findUserNote(int fd, int userUID)
{
    int noteUID = -1;
    unsigned char byte;
    int length;

    // Loop until a note for userUID is found
    // Filestream can also be used; higher-level I/O functions - easier to use (arguably) but are less direct.
    while (noteUID != userUID)
    {
        if (read(fd, &noteUID, 4) != 4) { return -1; } //If 4 bytes aren't read, return end of file code
        if (read(fd, &byte, 1) != 1) { return -1; } // Read the newline separator

        byte = length = 0;

        // Determine number of bytes to end of line
        while (byte != '\n') 
        {
            if (read(fd, &byte, 1) != 1) { return -1; } // If byte isn't read, return end of file code
            length++;
        }
    }

    lseek(fd, length * -1, SEEK_CUR); // Seek file to beginning of note (negative number seeks backwards)

    printf("[DEBUG] found a %d byte note for user id %d\n", length, noteUID);

    return length;
}

// A function to search a note for a given keyword.
// Returns 1 if a match is found, 0 if there is no match.
int searchNote(char *note, char *keyword)
{
    int i, keywordLength, match = 0;

    keywordLength = strlen(keyword);
    if(keywordLength == 0) { return 1; } // If there is no search string, always match

    // Iterate over bytes in note (letter by letter)
    for (int i = 0; i < strlen(note); i++) 
    {
        // If byte matches current to-be-matched keyword byte, get ready to check next byte
        if (note[i] == keyword[match]) 
        { 
            match++; 
        }
        else 
        {
            if (note[i] == keyword[0]) { match = 1; } // If byte matches first byte in keyword, check next
            else { match = 0; }
        }

        if (match == keywordLength) { return 1; } // If there is full match
    }

    return 0; // Return not matched
}
