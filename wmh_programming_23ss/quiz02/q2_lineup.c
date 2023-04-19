#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack{
    struct stack* next;
    char* name;
}Stack;

void push(Stack* st, char* str){
    while (st->next!=NULL)
    {
        st=st->next;
    }
    st->next=(Stack*)malloc(sizeof(Stack));
    st=st->next;
    st->name=(char*)malloc(sizeof(strlen(str)+1));
    strcpy(st->name,str);
    st->next=NULL;
    return;
}

void pop(Stack* st){
    Stack *temp;
    temp=st->next;
    st->next=st->next->next;
    free(temp);
}

int main(){
    char str[10000];
    Stack* st=(Stack*)malloc(sizeof(Stack)), *temp;
    while (scanf("%s",str)!=EOF)
    {   
        if(strcmp(str,"new")==0){
            scanf("%s",str);
            push(st, str);
        }
        else{
            pop(st);
        }
    }
    st=st->next;
    while (st!=NULL)
    {
        printf("%s\n",st->name);
        temp=st;
        st=st->next;
        free(temp);
    }
    
    
}