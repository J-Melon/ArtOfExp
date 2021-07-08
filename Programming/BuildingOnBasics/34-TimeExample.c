// Prints the current time (GMT).
// Shows that structs are a collection of variables.
// They can be accessed directly or via pointer. 
// Or by dereferencing and typecasting the pointer pointing to the struct (this gets the first element only). 

#include <stdio.h>
#include <time.h>

int main(void) 
{
    long int secondsSinceEpoch;
    struct tm currentTime, *timePtr;
    int hour, minute, second, day, month, year;

    secondsSinceEpoch = time(0); // Pass time a null pointer as an argument.
    printf("time() - seconds since epoch: %ld\n", secondsSinceEpoch);

    timePtr = &currentTime; // Set timePtr to the address of the currentTime struct.
    gmtime_r(&secondsSinceEpoch, timePtr);

    // Three different ways to access struct elements:
    hour = currentTime.tm_hour; // Direct access
    minute = timePtr -> tm_min; // Access via pointer
    second = *((int *) timePtr); // Hacky pointer access

    printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);
}
