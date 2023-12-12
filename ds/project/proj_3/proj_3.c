#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 30000 // i guess the number of request may not exceed this number

typedef struct Link{ // adjacdncy list
    int val;
    struct Link* next;
}link;
typedef struct Stack{
    struct Stack* prev;
    int val;
}stack;
typedef struct Queue{
    struct Queue* prev;
    struct Queue* next;
    int val;
}queue;
int nodes, links, timeSlots, requests;
int request[NUM][3];
int *memories;
link **adjacencyList;
int bfsResult[NUM][2]; // this array stores the number of hop each request takes according to bfs
stack **bfsPath;

int stackTop(stack** s){
    return (*s)->val;
}

int stackEmpty(stack** s){
    if((*s)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void stackPop(stack** s){
    stack* temp=(*s);
    (*s)=(*s)->prev;
    free(temp);
    return;
}

void stackPush(stack** s, int value){
    stack* ptr=(stack*)malloc(sizeof(stack));
    ptr->prev=(*s);
    ptr->val=value;
    (*s)=ptr;
    return;
}

int bfsTraverse(int requestId, int* visited, stack** s){
    
    int current=stackTop(s), temp;
    visited[current]=1;
    stackPop(s);
    // printf("current=%d\n", current);
    if(current==request[requestId][2]){// destinaction reached
        stackPush(&(bfsPath[requestId]), current);
        return 1; //remember to minus 1
    }
    else{
        link* ptr=adjacencyList[current];
        while(ptr!=NULL){
            if(visited[ptr->val]==0){
                stackPush(s, ptr->val);
            }
            ptr=ptr->next;
        }
        if(stackEmpty(s)==0){
            temp=bfsTraverse(requestId, visited, s);
            if(temp!=0){
                stackPush(&(bfsPath[requestId]), current);
                return temp+1;
            }
        }

    }
    return 0;

}

int bfs(int requestId){
    int hop=0;
    int visisted[nodes];
    stack* myStack=NULL;
    memset(visisted, 0, sizeof(visisted)); //initialize the array
    printf("source %d destination %d\n",request[requestId][1], request[requestId][2]);
    stackPush(&myStack, request[requestId][1]);
    return bfsTraverse(requestId, visisted, &myStack);
}

int main(){
    int tempA, tempB, temp, tempArr[2];
    link* tempPtr;
    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));
    bfsPath=(stack**)malloc(requests*sizeof(stack*));
    for(int i=0;i<NUM;i++){
        bfsResult[i][0]=i;
    }
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

    for(int i=0;i<requests;i++){
        bfsResult[i][1]=bfs(i)-1;
        // printf("#%d %d step\n", i, bfsResult[i][1]);
        // stack* ptr=bfsPath[i];
        // while(ptr!=NULL){
        //     printf("%d ",ptr->val);
        //     ptr=ptr->prev;
        // }
        // printf("\n");        
    }
    for(int i=0;i<requests;i++){
        for(int j=0;j<requests-i;j++){
            if(bfsResult[j][1]>bfsResult[j+1][1]){
                temp=bfsResult[j][0];
                bfsResult[j][0]=bfsResult[j+1][0];
                bfsResult[j+1][0]=temp;
                temp=bfsResult[j][1];
                bfsResult[j][1]=bfsResult[j+1][1];
                bfsResult[j+1][1]=temp;
            }
        }
    }
    for(int i=requests-1;i>=0;i--){
        // printf("#%d %d step\n", i, bfsResult[i][1]);
        stack* ptr=bfsPath[i];
        while(ptr!=NULL){
            // printf("%d ",ptr->val);
            ptr=ptr->prev;
        }
        // printf("\n");        
    }    
}