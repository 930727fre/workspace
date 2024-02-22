#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 30000 // i guess the number of request may not exceed this number

typedef struct Link{ // adjacdncy list
    int val;
    struct Link* next;
    struct Link* prev;
}link;

int nodes, links, timeSlots, requests;
int request[NUM][3];
int *memories;
int bfsResult[NUM][2]; // this array stores the number of hop each request takes according to bfs


link **adjacencyList;
link **bfsPath;

void enqueue(link** front, link** rear, int value){
    if((*front)==NULL){
        (*front)=(link*)malloc(sizeof(link));
        (*front)->val=value;
        (*rear)=(*front);
        return;
    }
    else{
        (*rear)->prev=(link*)malloc(sizeof(link));
        (*rear)=(*rear)->prev;
        (*rear)->val=value;
        (*rear)->prev=NULL;
        return;
    }

}

void dequeue(link** front, link** rear){
    link* ptr=(*front);
    (*front)=(*front)->prev;
    free(ptr);
    if((*front)==NULL){
        (*rear)=NULL;
    }
    return;
}

int queueEmpty(link** front){
    if((*front)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int queueFront(link** front){
    return (*front)->val;
}

int stackTop(link** s){
    return (*s)->val;
}

int stackEmpty(link** s){
    if((*s)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void pop(link** s){
    link* temp=(*s);
    (*s)=(*s)->prev;
    free(temp);
    return;
}

void push(link** s, int value){
    link* ptr=(link*)malloc(sizeof(link));
    ptr->prev=(*s);
    ptr->val=value;
    (*s)=ptr;
    return;
}

void bfsBacktrace(int requestId, int* parent, int temp){
    push(&(bfsPath[requestId]), temp);
    if(parent[temp]!=-1){
        bfsBacktrace(requestId, parent, temp);
    }
}

int bfsTraverse(int requestId, int* visited, int* parent, link** front, link** rear){
    int current=queueFront(front), temp;
    dequeue(front, rear);
    if(current==request[requestId][2]){// destinaction reached
        bfsBacktrace(requestId, parent, current);
        return 1; //remember to minus 1
    }
    else{
        link* ptr=adjacencyList[current];
        while(ptr!=NULL){
            if(visited[ptr->val]==0){
                enqueue(front, rear, ptr->val);
                visited[current]=1;
                parent[ptr->val]=current;
            }
            ptr=ptr->next;
        }
        if(queueEmpty(front)==0){
            temp=bfsTraverse(requestId, visited, parent, front, rear);
            if(temp!=0){
                push(&(bfsPath[requestId]), current);
                return temp+1;
            }
        }

    }
    return 0;
}

int bfs(int requestId){
    int hop=0;
    int visited[nodes], parent[nodes];
    link *rear=NULL, *front=NULL;
    memset(visited, 0, sizeof(visited)); //initialize the array
    memset(parent, -1, sizeof(parent));
    enqueue(&front, &rear, request[requestId][1]);
    visited[request[requestId][1]]=1;
    return bfsTraverse(requestId, visited, parent, &front, &rear);
}





int main(){
    int tempA, tempB, temp, tempArr[2];
    link* tempPtr;

    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));
    bfsPath=(link**)malloc(requests*sizeof(link*));
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
        link* ptr=bfsPath[i];
        while(ptr!=NULL){
            // printf("%d ",ptr->val);
            ptr=ptr->prev;
        }
        // printf("\n");        
    }    
}