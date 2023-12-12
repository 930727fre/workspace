#include <stdio.h>
#include <stdlib.h>
#define NUM 30000 // i guess the number of request may not exceed this number

typedef struct Link{ // adjacdncy list
    int val;
    struct Link* next;
}link;
typedef struct Queue{
    struct Queue* prev;
    int val;
}queue;
int nodes, links, timeSlots, requests;
int request[NUM][3];
int *memories;
link **adjacencyList;
int bfsResult[NUM]; // this array stores the number of hop each request takes according to bfs

int queueTop(queue** q){
    return (*q)->val;
}

int queueEmpty(queue** q){
    if((*q)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void queuePop(queue** q){
    queue* temp=(*q);
    (*q)=(*q)->prev;
    free(temp);
    return;
}

void queuePush(queue** q, int value){
    queue* ptr=(queue*)malloc(sizeof(queue));
    ptr->prev=(*q);
    ptr->val=value;
    (*q)=ptr;
    return;
}

int bfs(int start, int dest){ // the return value is the number of hop
    int hop=0;
    queue* myQueue=NULL;
    queuePush(&myQueue, 3);

    return 3;
}

int main(){
    int tempA, tempB, temp;
    link* tempPtr;
    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));
    bfs(0,1);
    return 0;
    for(int i=0;i<nodes;i++){
        scanf("%d %d",&tempA, &memories[i]);
    }
    for(int i=0;i<links;i++){
        scanf("%d %d %d", &temp, &tempA, &tempB);
        if(adjacencyList[tempA]==NULL){ // insert tempB into adjacency list
            adjacencyList[tempA]=(link*)malloc(sizeof(link));
            adjacencyList[tempA]->val=tempB;
            adjacencyList[tempA]->next=NULL;
        }
        else{
            tempPtr=adjacencyList[tempA];
            while(tempPtr->next!=NULL){
                tempPtr=tempPtr->next;
            }
            tempPtr->next=(link*)malloc(sizeof(link));
            tempPtr=tempPtr->next;
            tempPtr->val=tempB;
            tempPtr->next=NULL;
        }

        if(adjacencyList[tempB]==NULL){ // insert tempA int o adjacency list
            adjacencyList[tempB]=(link*)malloc(sizeof(link));
            adjacencyList[tempB]->val=tempA;
            adjacencyList[tempB]->next=NULL;
        }
        else{
            tempPtr=adjacencyList[tempB];
            while(tempPtr->next!=NULL){
                tempPtr=tempPtr->next;
            }
            tempPtr->next=(link*)malloc(sizeof(link));
            tempPtr=tempPtr->next;
            tempPtr->val=tempA;
            tempPtr->next=NULL;

        }
    }
    for(int i=0;i<requests;i++){
        scanf("%d %d %d",&request[i][0],&request[i][1],&request[i][2]);
    }   

}