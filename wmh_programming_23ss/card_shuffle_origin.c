#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 52

typedef struct card
{
    int face; // 1 to 13
    char suit; // C -> Club; D -> Diamond; H -> Heart; S -> Spade
    struct card *next;
} Card;

Card *newCardStack()
{

}

void printCardStack(Card *cardStack)
{

}

void shuffleCardStack(Card **cardStack)
{

}

void freeCardStack(Card **cardStack)
{

}

int main()
{
    srand(time(NULL));
    Card *cardStack = newCardStack();
    printCardStack(cardStack);
    shuffleCardStack(&cardStack);
    printCardStack(cardStack);
    freeCardStack(&cardStack);
}
