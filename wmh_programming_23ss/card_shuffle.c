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
    Card *b=(Card*)malloc(sizeof(Card*));
    Card *a_prev=(Card*)malloc(sizeof(Card*));
    Card *b_prev=(Card*)malloc(sizeof(Card*));
    Card *a=(Card*)malloc(sizeof(Card*));
    Card *temp=(Card*)malloc(sizeof(Card*));
    a=(*cardStack);
    a_prev=NULL;
    b_prev=NULL;
    for(int i=1;i<=52;i++){
        int random_num = rand()%52+1;
        printf("%d\n",random_num);
        while(i==random_num){
            random_num = rand()%52+1;
        }
        b=(*cardStack);
        for(int i=0;i<random_num;i++){
            b_prev=b;
            b=b->next;
        }
        if(a_prev!=NULL){
            a_prev->next=b;
        }
        if(b_prev!=NULL){
            b_prev->next=a;
        }
        temp->next=a->next;
        a->next=b->next;
        b->next=temp->next;
        a_prev=b;
        a=b->next;
    }

}

void freeCardStack(Card **cardStack)
{   
    if((*cardStack)->next==NULL){
        free(*cardStack);
        return;
    }
    else{
        freeCardStack(&((*cardStack)->next));
        free(*cardStack);
    }
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
