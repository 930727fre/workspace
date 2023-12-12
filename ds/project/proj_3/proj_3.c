#include <stdio.h>
#include <stdlib.h>

typedef struct Link{ // adjacdncy list
    int val;
    struct Link* next;
}link;
int nodes, links, timeSlots, requests;
int *memories;
link **adjacencyList;

int main(){
    int tempA, tempB, temp;
    link* tempPtr;
    scanf("%d %d %d %d",&nodes, &links, &timeSlots, &requests);
    memories=(int*)malloc(nodes*sizeof(int));
    adjacencyList=(link**)malloc(nodes*sizeof(link*));

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

    for(int i=0;i<nodes;i++){
        printf("%d:\n",i);
        tempPtr=adjacencyList[i];
        while(tempPtr!=NULL){
            printf("%d ", tempPtr->val);
            tempPtr=tempPtr->next;
        }
        printf("\n");
        
    }
}