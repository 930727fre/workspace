#include <stdio.h>
#include <stdlib.h>

int *new, *old, *current, *updated, *unionSet;
int updateCounter=0, roundCounter=0;
typedef struct Queue{
    struct Queue *next;
    int n;
}queue;
queue** q;


void push(queue** q, int value){
    queue* temp=*q;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=(queue*)malloc(sizeof(queue));
    temp->next->n=value;
    return;
}

int top(queue** q){
    if((*q)->next==NULL){
        return -1;
    }
    else{
        return (*q)->next->n;
    }
}

void pop(queue** q){
    queue* temp;
    if((*q)->next==NULL){
        return;
    }
    else{
        temp=*q;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

int dsuFind(int a){
    if(a==unionSet[a]){
        return a;
    }
    else{
        unionSet[a]=dsuFind(unionSet[a]);
        return unionSet[a];
    }
}

void dsuUnion(int a, int b){
    int temp1=dsuFind(a);
    int temp2=dsuFind(b);
    unionSet[temp2]=temp1;
}

int main(){
    int n;
    scanf("%d",&n);
    new=(int*)calloc(n,sizeof(int));
    old=(int*)calloc(n,sizeof(int));
    current=(int*)calloc(n,sizeof(int));
    updated=(int*)calloc(n,sizeof(int));
    unionSet=(int*)calloc(n,sizeof(int));
    q=(queue**)malloc(sizeof(queue*));
    *q=(queue*)malloc(sizeof(queue));
    (*q)->next=NULL;

    for(int i=0;i<n;i++){// initialize union set
        unionSet[i]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&old[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&new[i]);
    }
}
