
#include <stdio.h>
#include <stdlib.h>         // for random
#include <string.h>         // ASK IF I CAN USE
#include <fcntl.h>          // For UNICODE graphics
#include <time.h>


#define CARD_NUMBERS_AMOUNT 13
#define CARD_TYPE_AMOUNT 4

#define HEART 0x2665
#define DIAMOND 0x2666
#define CLUBS 0x2663
#define SPADES 0x2660

#define VALID_ARGUMENTS_AMOUNT 3    // Path + 2 arguments
#define MIN_ARGV_LEN 1         // One digit + end of string
#define MAX_ARG_LEN 2         // Two digit + end of string
#define MIN_INPUT_RANGE 1
#define MAX_INPUT_RANGE 13

#define END_OF_STRING '\0'
#define FIRST_CHAR_INTEGER '0'
#define LAST_CHAR_INTEGER '9'

#define CARDS_PER_HAND_ARGV 1
#define PLAYERS_ARGV 2

#define UNICODE 0x00020000

#define DECK_SIZE 52

#define TRUE 1
#define FALSE 0
#define NO_ERRORS 0


void validateArgumentsAmount(int argumentAmount);
int validateArgument(char *argument);
int isCharValidInteger(char charToTest);
void validateInputCombination(int cardsPerHand, int players);
void invalidInputTerminate();

void setUnicodeMode();

void initializeDeck(int *deck);
void shuffleDeck(int *deck);
void swapElements(int *deck, int index1, int index2);
void drawHands(int deck[], int *hands, int players, int handSize);

void displayDeck(int deck[]);
void displayCard(int card);
void displayHands(int *hands, int players, int handSize);



