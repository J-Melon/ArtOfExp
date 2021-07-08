#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> // Maybe??
#include "hacking.h"

#define DATAFILE "/var/chance.data" // File to store user data

// Custom user struct to store information about users
struct user
{
    int uid;
    int credits;
    int highscore;
    char name[100];
    int (*currentGame) ();
};

// Function prototypes
int getPlayerData();
int registerNewPlayer();
void updatePlayerData();
void showHighscore();
void jackpot();
void inputName();
void printCards(char *, char *, int);
int takeWager(int, int);
void playTheGame();
int pickANumber();
int dealerNoMatch();
int findTheAce();
void fatal(char *);

// Global variables
struct user player; // Player struct

int main()
{
    int choice, lastGame;

    srand(time(0)); // Seed randomiser with current time

    // Try to read player data from file if no data, register new player
    if(getPlayerData() == -1) { registerNewPlayer(); }

    while(choice != 7)
    {
        printf("-=[ Game of Chance Menu ]=-\n");
        printf(" 1 - Play the Pick a Number game\n");
        printf(" 2 - Play the No Match Dealer game\n");
        printf(" 3 - Play the Find the Ace game\n");
        printf(" 4 - View current high score\n");
        printf(" 5 - Change your user name\n");
        printf("6 - Reset your account at 100 credits\n");
        printf("7 - Quit\n");
        printf("[Name: %s]\n", player.name);
        printf("[You have %u credits] -> ", player.credits);
        scanf("%d", &choice);

    }
}


















