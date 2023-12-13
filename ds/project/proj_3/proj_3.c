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
int bfsResult[NUM][3]; // this array stores requestId/ the number of hop/ request accepted or not
int **capacity;

link **adjacencyList;
link **bfsPath;

void printPath(int index){
    printf("#%d\n",bfsResult[index][0]);
    link* ptr=bfsPath[bfsResult[index][0]];
    while(ptr!=NULL){
        printf("%d ",ptr->val);
        ptr=ptr->prev;
    }
    printf("\n%d steps\n", bfsResult[index][1]);   
}

int check(int val, int tempCapacity[nodes][timeSlots], int time){
    if(tempCapacity[val][time]+1<=memories[val]){
        return 1;
    }
    else{
        return 0;
    }
}

int checkNumerology(int index){
    if(bfsResult[index][1]>timeSlots){
        return 0;
    }
    else{
        int arr[nodes], i=0, tempCapacity[nodes][timeSlots], time=timeSlots-1;
        link* ptr=bfsPath[bfsResult[index][0]];

        for(int i=0;i<nodes;i++){
            for(int j=0;j<timeSlots;j++){
                tempCapacity[i][j]=capacity[i][j];
            }
        }
        while(ptr!=NULL){
            arr[i]=ptr->val;
            i++;
            ptr=ptr->prev;
        }
        for(int i=bfsResult[index][1]-1;i>0;i--){
            if(i!=1){
                if(check(arr[i],tempCapacity, time)&&check(arr[0],tempCapacity, time)){
                    tempCapacity[arr[i]][time]++;
                    tempCapacity[arr[0]][time]++;
                }
                else{
                    return 0;
                }
                if(check(arr[i],tempCapacity, time-1)&&check(arr[i-1],tempCapacity, time-1)){
                    tempCapacity[arr[i]][time-1]++;
                    tempCapacity[arr[i-1]][time-1]++;
                }
                else{
                    return 0;
                }
                if(check(arr[i],tempCapacity, time-2)&&check(arr[i-1],tempCapacity, time-2)){
                    tempCapacity[arr[i]][time-2]++;
                    tempCapacity[arr[i-1]][time-2]++;
                } 
                else{
                    return 0;
                }   
            }
            else{
                if(check(arr[1],tempCapacity, time)&&check(arr[0],tempCapacity, time)){
                    tempCapacity[arr[1]][time]++;
                    tempCapacity[arr[0]][time]++;
                } 
                else{
                    return 0;
                }
                if(check(arr[1],tempCapacity, time-1)&&check(arr[0],tempCapacity, time-1)){
                    tempCapacity[arr[1]][time-1]++;
                    tempCapacity[arr[0]][time-1]++;
                } 
                else{
                    return 0;
                } 
            }
                    
            time--;
        }
       
        // for(int j=timeSlots-1;j>=0;j--){
        //     for(int i=0;i<nodes;i++){
        //         printf("%d",tempCapacity[i][j]);
        //     }
        //     printf("\n");
        // }   
        // printf("\n");

        for(int i=0;i<nodes;i++){
            for(int j=0;j<timeSlots;j++){
                capacity[i][j]=tempCapacity[i][j];
            }
        }       
        return 1;
    }
  
}

void enqueue(link** front, link** rear, int value){
    if((*front)==NULL){
        (*front)=(link*)malloc(sizeof(link));
        (*front)->val=value;
        (*front)->prev=NULL;
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
        bfsBacktrace(requestId, parent, parent[temp]);
    }
}

int bfsTraverse(int requestId, int* visited, int* parent, link** front, link** rear){
    int current=queueFront(front), temp;
    dequeue(front, rear);
    if(current==request[requestId][2]){// destinaction reached
        bfsBacktrace(requestId, parent, current);
        return 1;
    }
    else{
        link* ptr=adjacencyList[current];
        while(ptr!=NULL){
            if(visited[ptr->val]==0){
                enqueue(front, rear, ptr->val);
                visited[ptr->val]=1;
                parent[ptr->val]=current;
            }
            ptr=ptr->next;
        }
        if(queueEmpty(front)==0){
            bfsTraverse(requestId, visited, parent, front, rear);
        }

    }
    return 0;
}

int bfs(int requestId){
    int visited[nodes], parent[nodes];
    link *rear=NULL, *front=NULL;
    memset(visited, 0, sizeof(visited)); //initialize the array
    memset(parent, -1, sizeof(parent));
    enqueue(&front, &rear, request[requestId][1]);
    visited[request[requestId][1]]=1;
    return bfsTraverse(requestId, visited, parent, &front, &rear);
}





int main(){
    int tempA, tempB, temp, tempArr[2], counter, acceptedCounter=0;
    link* tempPtr;

    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));
    bfsPath=(link**)malloc(requests*sizeof(link*));
    capacity=(int**)malloc(nodes*sizeof(int*));
    memset(adjacencyList, 0, nodes*sizeof(link*));
    memset(bfsPath, 0, requests*sizeof(link*));

    for(int i=0;i<nodes;i++){
        capacity[i]=(int*)malloc(timeSlots*sizeof(int));
        for(int j=0;j<timeSlots;j++){
            capacity[i][j]=0;
        }
    }
    for(int i=0;i<NUM;i++){
        bfsResult[i][0]=i;
        bfsResult[i][2]=0;
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
    // for(int i=requests-1;i>=0;i--){
    for(int i=0;i<requests;i++){
        bfs(i);
        counter=0;
        link* ptr=bfsPath[i];
        while(ptr!=NULL){
            counter++;
            ptr=ptr->prev;
        }
        bfsResult[i][1]=counter;      
    }
    for(int i=0;i<requests;i++){
        for(int j=0;j<requests-i-1;j++){
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
    // for(int i=0;i<requests;i++){
    //     printPath(i);
    // }    
    for(int i=0;i<requests;i++){
        bfsResult[i][2]=checkNumerology(i);
    }

    for(int i=0;i<requests;i++){
        if(bfsResult[i][2]){
            printf("%d\n",i);
        }
    }

}