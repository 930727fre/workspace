#include <stdio.h> 
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *ptr;
}Node;
int pop_back(Node*);
void insertionSort(Node*, int);
int main(){
    Node *head=(Node*)malloc(sizeof(Node*));
    Node *sortedHead=(Node*)malloc(sizeof(Node*));
    head->ptr=NULL;
    sortedHead->ptr=NULL;

    int n,temp;
    scanf("%d %d",&n,&temp);
    sortedHead->value=temp;
    for(int i=1;i<n;i++){
        scanf("%d",&temp);
        insertionSort(sortedHead,temp);
    }

    for(int i=0;i<n;i++){
        printf("%d\n",pop_back(sortedHead));
    }
    free(head);
    free(sortedHead);
}



int pop_back(Node* head){
    // Node* lastNode=head;
    int temp;
    if(head->ptr==NULL){
        return head->value;
    }
    while((head->ptr)->ptr!=NULL){
        head=head->ptr;
    }// head becomes the last node after pop_back
    temp=(head->ptr)->value;
    free(head->ptr);
    head->ptr=NULL;
    // printf("%d\n",temp);
    return temp;
}


void insertionSort(Node* head, int value){
    Node* newNode=(Node*)malloc(sizeof(Node*));

    while(1){
        if(head->value>=value){
            newNode->value=head->value;
            head->value=value;
            newNode->ptr=head->ptr;
            head->ptr=newNode;
            return;
        }
        else{
            if(head->ptr==NULL){
                newNode->value=value;
                head->ptr=newNode;
                newNode->ptr=NULL;
                return;
            }
            head=head->ptr;
        }
    }
}