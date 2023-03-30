#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *prev;
    struct Node *next;
    int value;
}Node;
Node* mallocNode(void);
void push_back(Node*, int);
void freeLinkedList(Node*);
int main(){
    Node* head=mallocNode();
    Node* tail=mallocNode();
    Node* current=mallocNode();

    head->prev=NULL;
    head->next=tail;
    tail->prev=head;
    tail->next=NULL;


    for(int i=1;i<10;i++){
        push_back(tail, i);
    }
    current=head->next;
    while(current->next!=NULL){
        printf("%d ",current->value);
        current=current->next;
    }
    

    freeLinkedList(head);
}


void push_back(Node* tail, int value){
    Node* current=mallocNode();
    tail->prev->next=current;
    current->prev=tail->prev;
    current->value=value;
    current->next=tail;
    tail->prev=current;
}

Node* mallocNode(void){
    return (Node*)malloc(sizeof(Node*));
}

void freeLinkedList(Node* current){
    while(current->next!=NULL){
        current=current->next;
        free(current->prev);
    }
    free(current);
}