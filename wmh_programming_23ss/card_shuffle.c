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
    Card* head=(Card*)malloc(sizeof(Card*));
    Card* prev=(Card*)malloc(sizeof(Card*));
    prev=head;
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            Card* current=(Card*)malloc(sizeof(Card*));
            if(i==1&&j==1){
                current=head;
            }
            current->face=i;
            switch (j)
            {
                case 1:
                    current->suit='C';
                    break;
                case 2:
                    current->suit='D';
                    break;
                case 3:
                    current->suit='H';
                    break;
                case 4:
                    current->suit='s';
                    break;
            }
            prev->next=current;
            prev=current;
        }
    }
    prev->next=NULL;
    return head;
}

void printCardStack(Card *cardStack)
{
    Card* current=cardStack;
    while(1){
        printf("%d %c\n",current->face, current->suit);
        if(current->next==NULL){
            break;
        }
        else{
            current=current->next;
        }
    }
    return;
}

void shuffleCardStack(Card **cardStack)
{   
    Card *aPrev, *aNext, *bPrev, *bNext, *currentCard, *aCard, *bCard;
    int a,b;
    for(int i=0;i<52;i++){
        aPrev=NULL;
        bPrev=NULL;
        currentCard=*cardStack;
        a=rand()%52+1;
        b=rand()%52+1;
        while(a==b){
            b=rand()%52+1;
        }
        for(int j=1;a||b;j++){
            if(a==j){
                a=0;
                aCard=currentCard;
                aNext=currentCard->next;
            }
            else if(b==j){
                b=0;
                bCard=currentCard;
                bNext=currentCard->next;
            }
            if(a){
                aPrev=currentCard;
            }
            if(b){
                bPrev=currentCard;
            }
            if((a||b)&&currentCard->next==NULL){
                printf("unable to find\n");
                return;
            }
            currentCard=currentCard->next;
        }
        if(*cardStack==aCard){
            cardStack=&bCard;
        }
        else{
            aPrev->next=bCard;
        }
        if(*cardStack==bCard){
            cardStack=&aCard;
        }
        else{
            bPrev->next=aCard;
        }
        aCard->next=bNext;
        bCard->next=aNext;
        printf("%d %c\n",aCard->face,aCard->suit);
        printf("%d %c\n",bCard->face,bCard->suit);
        printCardStack(*cardStack);
    }

}

void freeCardStack(Card **cardStack)
{   
    Card *currentCard=*cardStack; 
    Card *tempCard;
    while(currentCard!=NULL){
        tempCard=currentCard;
        currentCard=currentCard->next;
        free(tempCard);
    }
    return;
}

int main()
{
    srand(time(NULL));
    Card *cardStack = newCardStack();
    // printCardStack(cardStack);
    printf("----------------\n");
    shuffleCardStack(&cardStack);
    // printCardStack(cardStack);
    freeCardStack(&cardStack);
}


