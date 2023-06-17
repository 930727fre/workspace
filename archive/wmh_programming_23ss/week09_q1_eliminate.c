#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack{
    int val;
    struct stack* prev;
    struct stack* next;
}Stack;

int ans;
void push(Stack* st, char word){
    if(st->next==NULL){
        st->next=(Stack*)malloc(sizeof(Stack));
        st->next->val=word;
        st->next->prev=NULL;
        st->next->next=NULL;
    }
    else{
        while(st->next!=NULL){
            st=st->next;
        }
        st->next=(Stack*)malloc(sizeof(Stack));
        st->next->val=word;
        st->next->prev=st;
        st->next->next=NULL;
    }
}

void eliminate(Stack* origin){
    Stack *temp, *st;
    st=origin->next;

    while(st->next!=NULL){

        if(st->val==st->next->val){
            if(st->prev==NULL){
                temp=st;
                if(st->next->next==NULL){
                    origin->next=NULL;
                    ans-=2;
                    return;
                }
                else{
                    st=st->next->next;
                    st->prev=NULL;
                    origin->next=st;
                    free(temp->next);
                    free(temp);
                }
            }
            else{
                temp=st;
                st=st->prev;
                st->next=st->next->next->next;
                if(st->next!=NULL){
                    st->next->prev=st;
                }
                free(temp->next);
                free(temp);
            }
            ans-=2;
        }
        else{
            st=st->next;
        }
    }
}

void freeStack(Stack* st){
    if(st->next!=NULL){
        freeStack(st->next);
    }
    free(st);

}


int main(){
    char str[200100];
    Stack* st=(Stack*)malloc(sizeof(Stack));
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        push(st,str[i]);
    }
    ans=strlen(str);
    eliminate(st);
    freeStack(st);
    printf("%d\n",ans);

}