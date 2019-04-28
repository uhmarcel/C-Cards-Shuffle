#include "cards.h"

const char CARD_NUM_SYMBOL[] = {'A', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'T', 'J', 'Q', 'K'};

const int CARD_TYPE_SYMBOL[] = {HEART, DIAMOND, CLUBS, SPADES};


void setUnicodeMode() {
    _setmode(_fileno(stdout), UNICODE);
}

void initializeDeck(int *deck) {
    int index = 0;
    for (index = 0; index < DECK_SIZE; index++) {
        *deck = index;
        deck++;
    }
}

void displayDeck(int deck[]) {
    int index = 0;
    for (index = 0; index < DECK_SIZE; index++) {
        if (index % CARD_NUMBERS_AMOUNT == 0) {     // DOCUMENT FORMULA
            wprintf(L"\n\n");                       // DOCUMENT WPRINTF
        }
        displayCard(deck[index]);
    }
    wprintf(L"\n\n");
}

void displayCard(int card) {
    int cardNumber = card % CARD_NUMBERS_AMOUNT;    // DOCUMENT FORMULA
    int cardType = card / CARD_NUMBERS_AMOUNT;      // DOCUMENT FORMULA

    wprintf(L"[ %c-%c ] ", CARD_NUM_SYMBOL[cardNumber], // DOCUMENT WPRINTF
                           CARD_TYPE_SYMBOL[cardType]);
    return;
}

void shuffleDeck(int *deck) {
    srand(time(0));
    int index = 0;
    int randomIndex = 0;

    for (index = DECK_SIZE - 1; index > 0; index--) {   // DOCUMENT THE SHIT OUT OF THIS
        randomIndex = rand() % (index + 1);   // DOCUMENT FORMULA
        swapElements(deck, index, randomIndex);
    }
}

void swapElements(int *deck, int index1, int index2) {
    int *firstPtr = deck + index1;
    int *secondPtr = deck + index2;
    int tmp = *firstPtr;
    *firstPtr = *secondPtr;
    *secondPtr = tmp;
}

void drawHands(int deck[], int *hands, int players, int handSize) {
    int cardsToDraw = players * handSize;
    int deckIndex = 0;
    int currentPlayer = 0;
    int handIndex = 0;
    int *currentPtr = NULL;

    for (deckIndex = 0; deckIndex < cardsToDraw; deckIndex++) {
        currentPlayer = deckIndex % players;
        handIndex = deckIndex / players;

        currentPtr = hands + (currentPlayer * handSize) + handIndex;   // DOCUMENT FORMULA
        *currentPtr =  deck[deckIndex];
    }
}

void displayHands(int *hands, int players, int handSize) {
    int playerIndex = 0;
    int handIndex = 0;
    int *currentPtr = NULL;

    for (playerIndex = 0; playerIndex < players; playerIndex++) {
        wprintf(L"\n\nPlayer  %d] - ", playerIndex + 1);
        for (handIndex = 0; handIndex < handSize; handIndex++) {
            currentPtr = hands + (playerIndex * handSize) + handIndex;
            displayCard(*currentPtr);
        }
    }
    wprintf(L"\n");
}
