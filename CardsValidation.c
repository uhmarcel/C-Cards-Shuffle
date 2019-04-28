#include "cards.h"

void validateArgumentsAmount(int argc) {
    if (argc != VALID_ARGUMENTS_AMOUNT) {
        invalidInputTerminate();
    }
}

int validateArgument(char *argument) {
    int argumentSize = strlen(argument);

    if ((argumentSize < MIN_ARGV_LEN) || (argumentSize > MAX_ARG_LEN)) {
        invalidInputTerminate();
    }

    int argToInteger = 0;

    for (; *argument != END_OF_STRING; argument++) {
        if (!isCharValidInteger(*argument)) {
            invalidInputTerminate();
        }
        argToInteger = (argToInteger * 10) + (*argument - FIRST_CHAR_INTEGER); // DOCUMENT FORMULA
    }

    if (argToInteger < MIN_INPUT_RANGE || argToInteger > MAX_INPUT_RANGE) {
        invalidInputTerminate();
    }

    return argToInteger;
}

int isCharValidInteger(char testChar) {
    if ((testChar < FIRST_CHAR_INTEGER) || (testChar > LAST_CHAR_INTEGER)) {
        return FALSE;
    }
    return TRUE;
}

void validateInputCombination(int cardsPerHand, int players) {
    if (cardsPerHand * players > DECK_SIZE) {
        invalidInputTerminate();
    }
}

void invalidInputTerminate() {  // Add meaningful message.
    puts("Invalid input. Program will terminate");
    exit(0);
}

