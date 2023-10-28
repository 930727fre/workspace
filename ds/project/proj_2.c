#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *new, *old, *updated, *backward, *unionSet;
int updateCounter=0, roundCounter=1, operation=0, n, current, temp;
typedef struct Queue{
    struct Queue *next;
    int n;
}queue;
queue **ans, **prune, **shortcut;


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

void push(queue** q, int value){
    queue* temp=*q;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=(queue*)malloc(sizeof(queue));
    temp->next->n=value;
    temp->next->next=NULL;
    return;
}

int top(queue** q){
    if((*q)->next==NULL){
        return INT_MIN;
        printf("top empty\n");
    }
    else{
        return (*q)->next->n;
    }
}

void pop(queue** q){
    queue* temp;
    if((*q)->next==NULL){
        printf("pop empty\n");
        return;
    }
    else{
        temp=(*q)->next;
        (*q)->next=(*q)->next->next;
        free(temp);
        return;
    }
}

int isEmpty(queue** q){
    if((*q)->next==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int findDestination(int i){
    while(updated[i]==1){
        i=new[i];
    }
    return i;
}

int skipCount(int i){
    int count=0, current=i, dest=new[i];
    dest=findDestination(new[i]);
    do{
        current=old[current];

        if(old[current]!=-1&&new[current]!=-1&&current!=dest&&updated[current]!=1){
            count++;
        }
    }while(current!=dest);
    return count;
}


void checkBackward(void){
    int current, dest;

    for(int i=0;i<n;i++){
        current=i;
        dest=findDestination(new[i]);
        if(updated[i]==1||old[i]==-1||new[i]==-1){
            backward[i]=-1;
            continue;
        }
        else{
            backward[i]=1;
            do{
                current=old[current];
                if(dsuFind(dest)==dsuFind(current)){// find old path counters new path with same dsu value
                    backward[i]=0;
                    break;
                }
            }while(current!=n-1);
        }
        // if(backward[i]){
        //     // printf("%d is backward\n",i);
        // }
        // else{
        //     printf("%d is forward\n",i);

        // }
    }
}

void addShortcut(int node){
    push(shortcut, node);
    updated[node]=1;
    dsuUnion(node, findDestination(node));
    push(ans, node);
    updateCounter++;
}



void pruneFunction(void){
    while(!isEmpty(shortcut)){
        int current=top(shortcut);
        pop(shortcut);
        int dest=findDestination(new[current]);
        current=old[current];
        while(current!=dest){
            if(old[current]!=-1&&new[current]!=-1&&updated[current]==0){
                push(prune, current);
            }
            current=old[current];
        }
    }
    if(isEmpty(prune)){ //no need to add roundCounter
        return;
    }
    while(!isEmpty(prune)){
        int temp=top(prune);
        pop(prune);
        dsuUnion(temp, findDestination(temp));
        push(ans, temp);
        updated[temp]=1;
        updateCounter++;
    }
    push(ans, -1);
    roundCounter++;   
}

void checkUpdated(void){
    for(int i=0;i<n;i++){
        printf("%d ", updated[i]);
    }
    printf("\n");
}


int main(){
    scanf("%d",&n);
    new=(int*)calloc(n,sizeof(int));
    old=(int*)calloc(n,sizeof(int));
    updated=(int*)calloc(n,sizeof(int));
    backward=(int*)calloc(n,sizeof(int));
    ans=(queue**)malloc(sizeof(queue*));
    unionSet=(int*)calloc(n,sizeof(int));

    *ans=(queue*)malloc(sizeof(queue));
    (*ans)->next=NULL;
    prune=(queue**)malloc(sizeof(queue*));
    *prune=(queue*)malloc(sizeof(queue));
    (*prune)->next=NULL;
    shortcut=(queue**)malloc(sizeof(queue*));
    *shortcut=(queue*)malloc(sizeof(queue));
    (*shortcut)->next=NULL;

    for(int i=0;i<n;i++){// input
        scanf("%d",&old[i]);
    }
    for(int i=0;i<n;i++){// input
        scanf("%d",&new[i]);
    }
    for(int i=0;i<n;i++){// initialize union set
        unionSet[i]=i;
    }

    roundCounter=1;
    push(ans,-1); // the output should start with inital state
    temp=0;


    for(int i=0;i<n;i++){
        if(new[i]!=-1&&old[i]==-1){
            push(ans,i);
            dsuUnion(i, findDestination(i));
            updateCounter++;
            updated[i]=1;
            temp=1;
        }
        if(new[i]!=old[i]){
            operation++;
        }
    }
    if(temp==1){ // this flag checks if there's any node pushed to ans, if so, then roundCounter++
        push(ans,-1);
        roundCounter++;
    }


    while(updateCounter!=operation){
        int maxIndex=-1, maxValue=INT_MIN;
        checkBackward();
        for(int i=0;i<n;i++){
            if(updated[i]==0&&new[i]!=-1&&backward[i]!=1){
                temp=skipCount(i);
                if(temp>maxValue){
                    maxValue=temp;
                    maxIndex=i;
                }
            }
        }
        if(maxIndex==-1){ // if no shortcut found
            break;
        }
        addShortcut(maxIndex);
        roundCounter++;
        push(ans, -1);
        pruneFunction();

    }

    temp=0;
    for(int i=0;i<n;i++){
        if(old[i]!=-1&&new[i]==-1){
            temp=1;
            push(ans,i);
            updateCounter++;
            updated[i]=1;
        }
    }

    if(temp==1){ // this flag checks if there's any node pushed to ans, if so, then roundCounter++
        push(ans,-1);
        roundCounter++;
    }

    // checkUpdated();

    // printf("updateCounter: %d\noperation: %d\nroundCounter: %d\n", updateCounter, operation, roundCounter);
    printf("%d\n",roundCounter);
    for(int i=0;i<roundCounter;i++){
        while(1){
            int temp=top(ans);
            pop(ans);
            if(temp==-1){
                break;
            }
            else{
                old[temp]=new[temp];
            }
        }
        for(int j=0;j<n;j++){
            printf("%d",old[j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        if(i!=roundCounter-1){
            printf("\n");
        }
    }
}
