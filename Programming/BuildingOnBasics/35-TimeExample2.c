// Dumps the contents of a time struct
// Shoes that elements of a struct can be accessed directly using an iterative pointer. 

#include <stdio.h>
#include <time.h>

void dumpTimeStructBytes(struct tm *timePtr, int size)
{
    int i;
    unsigned char *rawPtr;

    printf("bytes of struct located at %p", timePtr);
    rawPtr = (unsigned char *) timePtr;

    for (i = 0; i < size; i++)
    {
        printf("%02x ", rawPtr[i]);
        if (i % 16 == 15) { printf("\n"); } // Print a newline every 16 bytes
    }

    printf("\n");
}

int main(void)
{
    long int secondsSinceEpoch;
    struct tm currentTime, *timePtr;
    int hour, minute, second, i, *intPtr;

    secondsSinceEpoch = time(0); // Pass time a null pointer as argument
    printf("time() - seconds since epoch: %ld\n", secondsSinceEpoch);

    timePtr = &currentTime; // Set timePtr to the address of the currentTime struct
    gmtime_r(&secondsSinceEpoch, timePtr);

    hour = currentTime.tm_hour;
    minute = timePtr -> tm_min;
    second = *((int *) timePtr);

    printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);

    dumpTimeStructBytes(timePtr, sizeof(struct tm));

    minute = hour = 0; // Clear out minute and hour
    intPtr = (int *) timePtr;

    for (i = 0; i < 3; i++)
    {
        printf("intPtr @ %p : %d\n", intPtr, *intPtr);
        intPtr++; //Adding 1 to intPtr adds 4 to the address, since an int is 4 bytes in size
    }
}
