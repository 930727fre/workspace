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
        printf("dest %d\n",dest);
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
    while(!isEmpty(prune)){
        int temp=top(prune);
        pop(prune);
        push(ans, temp);
        updated[temp]=1;
        printf("pruned %d\n",temp);
        updateCounter++;
    }
}

void checkUpdated(void){
    for(int i=0;i<n;i++){
        printf("%d ", updated[i]);
    }    
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

    push(ans,-1); // the output should start with inital state
    for(int i=0;i<n;i++){
        if(new[i]!=-1&&old[i]==-1){
            push(ans,i);
        }
        if(new[i]!=old[i]){
            operation++;
        }
    }
    push(ans,-1);
    roundCounter+=1;

    // while(updateCounter!=operation){

    // }
    addShortcut(0);
    push(ans, -1);
    updateCounter++;
    roundCounter++;

    pruneFunction();
    push(ans, -1);
    roundCounter++;
    //
    temp=3;
    printf("skipCount %d %d\n",temp, skipCount(temp));        
    checkUpdated();
    printf("\n");
    for(int i=0;i<n;i++){
        if(old[i]!=-1&&new[i]==-1){
            push(ans,i);
        }
    }
    push(ans,-1);
    roundCounter+=1;
    // for(int i=0;i<n;i++){
    //     if(new[i]!=-1&&old[i]!=-1){
    //         printf("skip v%d %d\n",i,skipCount(i));
    //     }
    // }
    printf("%d\n", roundCounter);
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
