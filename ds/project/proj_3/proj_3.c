#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 30000 // i guess the number of request may not exceed this number

// Define a structure for a linked list node
typedef struct Link{ // adjacdncy list
    int val;
    struct Link* next;
    struct Link* prev;
}link;

int nodes, links, timeSlots, requests;
int request[NUM][3];
int *memories;
int bfsResult[NUM][4]; // this array stores requestId/ the number of node on the path/ request accepted or not/ optimized or not
int **capacity;

link **adjacencyList;
link **bfsPath;

void printOptimize(int index){
    int arr[nodes], i=0, T=timeSlots/2;
    link* ptr=bfsPath[bfsResult[index][0]];

    while(ptr!=NULL){
        arr[i]=ptr->val;
        i++;
        ptr=ptr->prev;
    }
    // Print the tree edges based on the BFS path
    printf("%d %d %d\n",arr[0], arr[1],T-bfsResult[index][1]+2);
    for(int i=2;i<bfsResult[index][1];i++){
        printf("%d %d %d\n", arr[i-1], arr[i], T-bfsResult[index][1]+i);
        printf("%d %d %d %d %d %d %d\n", arr[0], arr[i], arr[0], arr[i-1], arr[i-1], arr[i], T-bfsResult[index][1]+i+1);
    }    
}

// Function to print the tree based on the BFS path
void printTree(int index){
    int arr[nodes], i=0;
    link* ptr=bfsPath[bfsResult[index][0]];

    while(ptr!=NULL){
        arr[i]=ptr->val;
        i++;
        ptr=ptr->prev;
    }
    // Print the tree edges based on the BFS path
    printf("%d %d %d\n",arr[0], arr[1],timeSlots-bfsResult[index][1]+2);
    for(int i=2;i<bfsResult[index][1];i++){
        printf("%d %d %d\n", arr[i-1], arr[i], timeSlots-bfsResult[index][1]+i);
        printf("%d %d %d %d %d %d %d\n", arr[0], arr[i], arr[0], arr[i-1], arr[i-1], arr[i], timeSlots-bfsResult[index][1]+i+1);
    }    
}

// Function to print the nodes on the BFS path
void printPath(int index){
    printf("%d ",bfsResult[index][0]);
    // printf("#%d ",bfsResult[index][0]);
    link* ptr=bfsPath[bfsResult[index][0]];
    while(ptr!=NULL){
        printf("%d ",ptr->val);
        ptr=ptr->prev;
    }
    // printf("\n%d steps\n", bfsResult[index][1]);   
    printf("\n");
}

// Function to check if a node has enough capacity to accept a request
int check(int val, int tempCapacity[nodes][timeSlots], int time){
    if(tempCapacity[val][time]+1<=memories[val]){
        return 1; // Node has enough capacity
    }
    else{
        return 0; // Node does not have enough capacity
    }
}

int optimize(int index){
    int T=timeSlots/2;
    if(bfsResult[index][1]>T){
        return 0;  // Numerology is longer than timeSlot
    }
    else{
        int arr[nodes], i=0, tempCapacity[nodes][timeSlots], time=T-1;
        link* ptr=bfsPath[bfsResult[index][0]];

        // Copy the capacity array to a temporary array
        for(int i=0;i<nodes;i++){
            for(int j=0;j<timeSlots;j++){
                tempCapacity[i][j]=capacity[i][j];
            }
        }

        // Extract the nodes from the BFS path
        while(ptr!=NULL){
            arr[i]=ptr->val;
            i++;
            ptr=ptr->prev;
        }

        // Check numerology constraint for each time step
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
       
        // for(int j=T-1;j>=0;j--){
        //     for(int i=0;i<nodes;i++){
        //         printf("%d",tempCapacity[i][j]);
        //     }
        //     printf("\n");
        // }   
        // printf("\n");

        // Copy the updated temporary capacity array back to the main capacity array
        for(int i=0;i<nodes;i++){
            for(int j=0;j<timeSlots;j++){
                capacity[i][j]=tempCapacity[i][j];
            }
        }       
        return 1;
    }    

}

// Function to check the numerology constraint for a request
int checkNumerology(int index){
    if(bfsResult[index][1]>timeSlots){
        return 0;  // Numerology is longer than timeSlot
    }
    else{
        int arr[nodes], i=0, tempCapacity[nodes][timeSlots], time=timeSlots-1;
        link* ptr=bfsPath[bfsResult[index][0]];

        // Copy the capacity array to a temporary array
        for(int i=0;i<nodes;i++){
            for(int j=0;j<timeSlots;j++){
                tempCapacity[i][j]=capacity[i][j];
            }
        }

        // Extract the nodes from the BFS path
        while(ptr!=NULL){
            arr[i]=ptr->val;
            i++;
            ptr=ptr->prev;
        }

        // Check numerology constraint for each time step
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

        // Copy the updated temporary capacity array back to the main capacity array
        for(int i=0;i<nodes;i++){
            for(int j=0;j<timeSlots;j++){
                capacity[i][j]=tempCapacity[i][j];
            }
        }       
        return 1;
    }
  
}

// Function to enqueue a value in a linked list queue
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

// Function to dequeue a value from a linked list queue
void dequeue(link** front, link** rear){
    link* ptr=(*front);
    (*front)=(*front)->prev;
    free(ptr);
    if((*front)==NULL){
        (*rear)=NULL;
    }
    return;
}

// Function to check if a linked list queue is empty
int queueEmpty(link** front){
    if((*front)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to get the front value of a linked list queue
int queueFront(link** front){
    return (*front)->val;
}

// Function to get the top value of a linked list stack
int stackTop(link** s){
    return (*s)->val;
}

// Function to check if a linked list stack is empty
int stackEmpty(link** s){
    if((*s)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to pop a value from a linked list stack
void pop(link** s){
    link* temp=(*s);
    (*s)=(*s)->prev;
    free(temp);
    return;
}

// Function to push a value onto a linked list stack
void push(link** s, int value){
    link* ptr=(link*)malloc(sizeof(link));
    ptr->prev=(*s);
    ptr->val=value;
    (*s)=ptr;
    return;
}

// Function to backtrace the BFS path and store it in the linked list stack
void bfsBacktrace(int requestId, int* parent, int temp){
    push(&(bfsPath[requestId]), temp);
    if(parent[temp]!=-1){
        bfsBacktrace(requestId, parent, parent[temp]);
    }
}

// Function to perform BFS traversal on the graph
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

// Function to initiate BFS for a specific request
int bfs(int requestId){
    int visited[nodes], parent[nodes];
    link *rear=NULL, *front=NULL;
    memset(visited, 0, sizeof(visited)); //initialize the array
    memset(parent, -1, sizeof(parent));
    // Enqueue the starting node of the request
    enqueue(&front, &rear, request[requestId][1]);
    visited[request[requestId][1]]=1;
    return bfsTraverse(requestId, visited, parent, &front, &rear);
}


int main(){
    int tempA, tempB, temp, tempArr[2], counter, acceptedCounter=0;
    link* tempPtr;

    // Input the number of nodes, links, time slots, and requests
    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);

    // Allocate memory for arrays and initialize them
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));
    bfsPath=(link**)malloc(requests*sizeof(link*));
    capacity=(int**)malloc(nodes*sizeof(int*));
    memset(adjacencyList, 0, nodes*sizeof(link*));
    memset(bfsPath, 0, requests*sizeof(link*));

    // Initialize the capacity array
    for(int i=0;i<nodes;i++){
        capacity[i]=(int*)malloc(timeSlots*sizeof(int));
        for(int j=0;j<timeSlots;j++){
            capacity[i][j]=0;
        }
    }
    for(int i=0;i<NUM;i++){
        bfsResult[i][0]=i;
        bfsResult[i][2]=0;
        bfsResult[i][3]=0;
    }

    for(int i=0;i<nodes;i++){
        scanf("%d %d",&tempA, &memories[i]);
    }

    // put the edge to the adjacency list
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

    // perfrom bfs to all requests
    for(int i=0;i<requests;i++){
        bfs(i);
        counter=0;
        link* ptr=bfsPath[i];
        while(ptr!=NULL){
            counter++;
            ptr=ptr->prev;
        }
        // store the number of nodes on the path
        bfsResult[i][1]=counter;      
    }
    // bubble sort all the requests according to length of path
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

    // check if the numerology fits
    for(int i=0;i<requests;i++){
        bfsResult[i][2]=checkNumerology(i);
    }

    for(int i=0;i<requests;i++){
        if(bfsResult[i][2]==0){
            bfsResult[i][3]=optimize(i);
        }
    }

    // count the accepted requests
    for(int i=0;i<requests;i++){
        if(bfsResult[i][2]||bfsResult[i][3]){
            acceptedCounter++;
        }
    }

    // final output
    printf("%d\n",acceptedCounter);
    for(int i=0;i<requests;i++){
        if(bfsResult[i][2]){
            printPath(i);
            printTree(i);
        }
        else if(bfsResult[i][3]){
            printPath(i);
            printOptimize(i);
        }
    }

}