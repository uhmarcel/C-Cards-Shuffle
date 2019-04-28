#include "cards.h"

int main(int argc, char *argv[]) {

    int deck[DECK_SIZE] = {0};
    int cardsPerHand = 0;         // CHECK IF THEY HAVE TO BE CONSTANT
    int players = 0;

    validateArgumentsAmount(argc);
    cardsPerHand = validateArgument(argv[CARDS_PER_HAND_ARGV]);
    players = validateArgument(argv[PLAYERS_ARGV]);
    validateInputCombination(cardsPerHand, players);

    int hands[players][cardsPerHand];   // CHECK IF NEED CONSTANTS

    setUnicodeMode();

    wprintf(L"Original Ordered Deck:");
    initializeDeck(deck);
    displayDeck(deck);

    wprintf(L"Random Shuffled Deck:");
    shuffleDeck(deck);
    displayDeck(deck);

    wprintf(L"Player Hands: (dealt from top/front of deck)");
    drawHands(deck, &hands[0][0], players, cardsPerHand);
    displayHands(&hands[0][0], players, cardsPerHand);

    return NO_ERRORS;
}
