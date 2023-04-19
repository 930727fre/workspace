#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    struct stack *next;
    struct stack *prev;
    char val;
}Stack;

void push(Stack* cardStack, char val){
    if(cardStack->next==NULL){
        cardStack->next=(Stack*)malloc(sizeof(Stack));
        cardStack->next->prev=NULL;
        cardStack->next->val=val;
        return;
    }
    else{
        while(cardStack->next!=NULL){
            cardStack=cardStack->next;
        }
        cardStack->next=(Stack*)malloc(sizeof(Stack));
        cardStack->next->prev=cardStack;
        cardStack->next->val=val;
        return;
    }

}

Stack* eliminate(Stack* cardStack){
    Stack *current, *temp;
    current=cardStack->next;
    while (current->next!=NULL)
    {   
        if(current->val==current->next->val){
            if(current->prev!=NULL){
                current->prev->next=current->next->next;
                if(current->next->next!=NULL){
                    current->next->next->prev=current->prev;
                }
                temp=current->prev;
                free(current->next);
                free(current);
                current=temp;
            }
            else{
                temp=current->next->next;
                free(current->next);
                free(current);
                current=temp;
                cardStack=current;
                if(current==NULL){
                    return cardStack;
                }
                current->prev=NULL;
            }
        }
        else{
            current=current->next;
        }
    }
    temp=cardStack->next;
    free(cardStack);
    return temp;
}

int main(){
    char str[1000000];
    int ans=0;
    scanf("%s",str);
    Stack* st=(Stack*)malloc(sizeof(Stack)), *temp;
    for(int i=0;i<strlen(str);i++){
        push(st,str[i]);
    }
    st=eliminate(st);
    while (st!=NULL){
        ans++;
        temp=st;
        st=st->next;
        free(temp);
    }
    printf("%d\n",ans);
    
}
//abbaccdeffed