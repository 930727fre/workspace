#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    int val;
    struct stack* up;
}Stack;

void push(Stack* bottom, int val){
    Stack* search=bottom;
    while(search->up!=NULL){
        search=search->up;
    }
    search->up=(Stack*)malloc(sizeof(Stack*));
    search=search->up;
    search->up=NULL;
    search->val=val;
}

void pop(Stack* bottom){
    Stack *prev=NULL,*search=bottom->up;
    while(search!=NULL){
        prev=search;
        search=search->up;
    }
    if(search!=NULL){
        free(search);
    }
    prev->up=NULL;
}

int top(Stack* bottom){
    Stack* search=bottom->up;
    while(search->up!=NULL){
        search=search->up;
    }
    return search->val;
}

int size(Stack* bottom){
    Stack* search=bottom->up;
    int counter=0;
    while(search!=NULL){
        counter++;
        search=search->up;
    }
    return counter;
}

int main(){
    Stack* bottom=(Stack*)malloc(sizeof(Stack*));
    bottom->up=NULL;
    printf("%d",size(bottom));
}