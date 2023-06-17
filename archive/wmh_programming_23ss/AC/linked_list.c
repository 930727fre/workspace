#include <stdio.h> 
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *ptr;
}Node;
void push_back(Node*, int);
void insert(Node*, int, int);
void delete(Node*, int);
void pop_back(Node*);
int find(Node*, int);
int main(){
    Node *head=(Node*)malloc(sizeof(Node*));
    head->ptr=NULL;
    insert(head,1,88);
    push_back(head,3);
    find(head,3)? printf("found\n"):printf("can't find\n");
    pop_back(head);
    pop_back(head);
    pop_back(head);
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

void pop_back(Node* head){
    // Node* lastNode=head;
    int temp;
    if(head->ptr==NULL){
        printf("The linked list is void\n");
        return;
    }
    while((head->ptr)->ptr!=NULL){
        head=head->ptr;
    }// head becomes the last node after pop_back
    temp=(head->ptr)->value;
    free(head->ptr);
    head->ptr=NULL;
    printf("%d\n",temp);
    return;
}
void insert(Node* head, int index, int newValue){
    if(index==0){
        printf("you can't insert at index 0 \n");
        return;
    }
    for(int i=0;i<index-1;i++){
        if(head==NULL){
            printf("index %d doesn't exist\n",index);
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

void delete(Node* head, int index){
    Node* prev;
    if(index==0&&head->ptr==NULL){
        printf("unable to delete the head of linked list\n");
        return;
    }
    else{
        for(int i=1;i<index;i++){
            prev=head;
            head=head->ptr;
            if(head->ptr==NULL){
                printf("unable to delete element of index %d\n",index);
                return;
            }
        }
    }
    prev->ptr=NULL;
    free(head);
}

int find(Node* head, int value){
    while(1){
        if(head==NULL){
            return 0;
        }
        else{
            if(head->value==value){
                return 1;
            }
            head=head->ptr;
        }
    }
}