#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *new, *old, *updated, *unionSet;
int updateCounter=0, roundCounter=1, operation=0, n, current, temp;
typedef struct Queue{
    struct Queue *next;
    int n;
}queue;
queue **q, **ans, **prune, **shortcut;


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
    int count=0, current=i, dest=new[i], prevUpdated=0;
    dest=findDestination(new[i]);
    do{
        if(current==-1){
            return -1;
        }
        current=old[current];

        if(old[current]!=-1&&new[current]!=-1&&current!=dest){
            if(updated[current]==1){
                if(prevUpdated==1){
                    continue;
                }
                else{
                    prevUpdated=1;
                }
            }
            else{
                prevUpdated=0;
            }
            count++;
        }
    }while(current!=dest);
    return count;
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

void addShortcut(int node){
    push(shortcut, node);
    updated[node]=1;
}

void pruneFunction(void){
    while(!isEmpty(shortcut)){
        int current=top(shortcut);
        pop(shortcut);
        int dest=findDestination(new[current]);
        if(skipCount(current)==-1){
            updated[current]=1;
            push(ans, current);
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
        printf("pruned %d\n",temp);
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
    unionSet=(int*)calloc(n,sizeof(int));
    q=(queue**)malloc(sizeof(queue*));
    *q=(queue*)malloc(sizeof(queue));
    (*q)->next=NULL;
    ans=(queue**)malloc(sizeof(queue*));
    *ans=(queue*)malloc(sizeof(queue));
    (*ans)->next=NULL;
    prune=(queue**)malloc(sizeof(queue*));
    *prune=(queue*)malloc(sizeof(queue));
    (*prune)->next=NULL;
    shortcut=(queue**)malloc(sizeof(queue*));
    *shortcut=(queue*)malloc(sizeof(queue));
    (*shortcut)->next=NULL;

    for(int i=0;i<n;i++){// initialize union set
        unionSet[i]=i;
    }
    for(int i=0;i<n;i++){// input
        scanf("%d",&old[i]);
    }
    for(int i=0;i<n;i++){// input
        scanf("%d",&new[i]);
    }
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

    // addShortcut(3);
    // push(ans, -1);
    // updateCounter++;
    // roundCounter++;
    // pruneFunction();

    // addShortcut(0);
    // updateCounter++;
    // addShortcut(8);
    // updateCounter++;
    // push(ans, -1);
    // roundCounter++;
    // pruneFunction();  

    // addShortcut(2);
    // push(ans, -1);
    // updateCounter++;
    // roundCounter++;
    // pruneFunction();

    addShortcut(0);
    push(ans, -1);
    updateCounter++;
    roundCounter++;
    pruneFunction();

    addShortcut(3);
    push(ans, -1);
    updateCounter++;
    roundCounter++;
    pruneFunction();        

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

    checkUpdated();

    printf("updateCounter: %d\noperation: %d\nroundCounter: %d\n", updateCounter, operation, roundCounter);
    // for(int i=0;i<roundCounter;i++){
    //     while(1){
    //         int temp=top(ans);
    //         pop(ans);
    //         if(temp==-1){
    //             break;
    //         }
    //         else{
    //             old[temp]=new[temp];
    //         }
    //     }
    //     for(int j=0;j<n;j++){
    //         printf("%d",old[j]);
    //         if(j!=n-1){
    //             printf(" ");
    //         }
    //     }
    //     if(i!=roundCounter-1){
    //         printf("\n");
    //     }
    // }
}
