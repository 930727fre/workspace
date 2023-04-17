#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans=0;
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

void eliminate(Stack* cardStack){
    Stack *current, *temp;
    current=cardStack->next;
    while (current->next!=NULL)
    {   
        if(current->val==current->next->val){
            ans++;
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
                if(current==NULL){
                    return;
                }
                current->prev=NULL;
            }
        }
        else{
            current=current->next;
        }
    }
    
}

int main(){
    char str[1000000];
    scanf("%s",str);
    Stack* st=(Stack*)malloc(sizeof(Stack));
    for(int i=0;i<strlen(str);i++){
        push(st,str[i]);
    }
    eliminate(st);
    free(st);
    printf("%d\n",ans);

    
}
//abbaccdeffed