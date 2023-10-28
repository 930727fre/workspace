#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *new, *old, *updated, *backward;
int updateCounter=0, roundCounter=1, operation=0, n, current, temp;
typedef struct Queue{
    struct Queue *next;
    int n;
}queue;
queue **ans, **prune, **shortcut;


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
    while((old[i]==-1&&i!=n-1)||updated[i]==1){
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

void addShortcut(int node){
    push(shortcut, node);
    updated[node]=1;
    push(ans, node);
    updateCounter++;
}


void checkBackward(void){
    int current, dest;
    for(int i=0;i<n;i++){
        current=i;
        dest=findDestination(new[i]);
        do{
            if(current==-1){// if you reached the end before countering dest, then it's a backward
                backward[i]=1;
                break;
            }
            current=old[current];
        }while(current!=dest);
    }
}

void pruneFunction(void){
    while(!isEmpty(shortcut)){
        int current=top(shortcut);
        pop(shortcut);
        int dest=findDestination(new[current]);
        if(backward[current]==1){ //a shortcut is backward
            continue;
        }
        else{
            current=old[current];
            while(current!=dest){
                if(old[current]!=-1&&new[current]!=-1&&updated[current]==0){
                    push(prune, current);
                }
                current=old[current];
            }
        }
    }
    if(isEmpty(prune)){ //no need to add roundCounter
        return;
    }
    while(!isEmpty(prune)){
        int temp=top(prune);
        pop(prune);
        push(ans, temp);
        updated[temp]=1;
        updateCounter++;
    }
    push(ans, -1);
    roundCounter++;   
    checkBackward();
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

    checkBackward();
    roundCounter=1;
    push(ans,-1); // the output should start with inital state
    temp=0;
    for(int i=0;i<n;i++){
        if(new[i]!=-1&&old[i]==-1){
            push(ans,i);
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
    
    temp=0;// act as a flag to check if there's any node pushed in this round
    for(int i=0;i<n;i++){
        if(backward[i]==1&&updated[i]!=1&&old[i]!=-1&&new[i]!=-1){
            push(ans, i);
            updated[i]=1;
            temp=1;
            updateCounter++;
        }
    }
    if(temp==1){
        push(ans, -1);
        roundCounter++;
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
