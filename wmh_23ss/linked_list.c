#include <stdio.h> 
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *ptr;
}Node;
void push_back(Node*, int);
void insert(Node*, int, int);
void delete(Node*, int);
int pop_back(Node*);
int main(){
    Node *head=(Node*)malloc(sizeof(Node*));
    head->ptr=NULL;
     insert(head,0,88);
    push_back(head,3);
    printf("%d\n",pop_back(head));
    printf("%d\n",pop_back(head));
    printf("%d\n",pop_back(head));

}


void push_back(Node* head, int newValue){
    while(head->ptr!=NULL){
        head=head->ptr;
    }
    Node *newNode=(Node*)malloc(sizeof(Node*));
    head->ptr=newNode;
    newNode->value=newValue;
    newNode->ptr=NULL;
    return;
}

int pop_back(Node* head){
    // Node* lastNode=head;
    int temp;
    if(head->ptr==NULL){
        printf("The linked list is void\n");
        return -1;
    }
    while((head->ptr)->ptr!=NULL){
        head=head->ptr;
    }// head becomes the last node after pop_back
    temp=(head->ptr)->value;
    free(head->ptr);
    head->ptr=NULL;
    return temp;
}
void insert(Node* head, int index, int newValue){
    for(int i=0;i<index;i++){
        if(head->ptr==NULL){
            printf("index is greater than the size of this linked list.\n");
            return;
        }
        else{
            head=head->ptr;
        }
    }
    Node *newNode=(Node*)malloc(sizeof(Node*));
    newNode->ptr=head->ptr;
    newNode->value=newValue;
    head->ptr=newNode;
}
void delete(Node*, int index){

}