#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
queue **bfsPath;

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

int bfsTraverse(int requestId, int* visited, queue** q){
    
    int current=queueTop(q), temp;
    visited[current]=1;
    queuePop(q);
    printf("current=%d\n", current);
    if(current==request[requestId][2]){// destinaction reached
        queuePush(&(bfsPath[requestId]), current);
        return 1; //remember to minus 1
    }
    else{
        link* ptr=adjacencyList[current];
        while(ptr!=NULL){
            queuePush(q, ptr->val);
            ptr=ptr->next;
        }
        temp=bfsTraverse(requestId, visited, q);
        if(temp!=0){
            queuePush(&(bfsPath[requestId]), current);
            return temp+1;
        }
        else{
            return 0;
        }
    }

}

int bfs(int requestId){
    int hop=0;
    int visisted[nodes];
    queue* myQueue=NULL;
    memset(visisted, 0, sizeof(visisted)); //initialize the array
    queuePush(&myQueue, request[requestId][1]);
    return bfsTraverse(requestId, visisted, &myQueue);
}

int main(){
    int tempA, tempB, temp;
    link* tempPtr;
    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));
    bfsPath=(queue**)malloc(requests*sizeof(queue*));
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

    for(int i=0;i<1;i++){
        bfsResult[i]=bfs(i)-1;
        printf("#%d %dstep\n", i, bfsResult[i]);
        queue* ptr=bfsPath[i];
        while(ptr!=NULL){
            printf("%d ",ptr->val);
            ptr=ptr->prev;
        }
        printf("\n");        

    }

}