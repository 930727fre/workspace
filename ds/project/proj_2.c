#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *new, *old, *current, *updated, *unionSet;
int updateCounter=0, roundCounter=1, operation=0, n;
typedef struct Queue{
    struct Queue *next;
    int n;
}queue;
queue** q;
queue** ans;


void push(queue** q, int value){
    queue* temp=*q;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=(queue*)malloc(sizeof(queue));
    temp->next->n=value;
    return;
}

int top(queue** q){
    if((*q)->next==NULL){
        return INT_MIN;
    }
    else{
        return (*q)->next->n;
    }
}

void pop(queue** q){
    queue* temp;
    if((*q)->next==NULL){
        return;
    }
    else{
        temp=(*q)->next;
        (*q)->next=(*q)->next->next;
        free(temp);
        return;
    }
}

int skipCount(int i){
    int count=0, current=i, dest=new[i];
    while(old[dest]==-1&&dest!=n-1){
        dest=new[dest];
    }
    printf("dest %d\n",dest);
    do{
        if(current==-1){
            return -1;
        }
        current=old[current];
        if(old[current]!=-1&&new[current]!=-1&&current!=dest){
            printf("current %d\n",current);
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

int main(){
    scanf("%d",&n);
    new=(int*)calloc(n,sizeof(int));
    old=(int*)calloc(n,sizeof(int));
    current=(int*)calloc(n,sizeof(int));
    updated=(int*)calloc(n,sizeof(int));
    unionSet=(int*)calloc(n,sizeof(int));
    q=(queue**)malloc(sizeof(queue*));
    *q=(queue*)malloc(sizeof(queue));
    (*q)->next=NULL;
    ans=(queue**)malloc(sizeof(queue*));
    *ans=(queue*)malloc(sizeof(queue));
    (*ans)->next=NULL;    

    for(int i=0;i<n;i++){// initialize union set
        unionSet[i]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&old[i]);
    }
    for(int i=0;i<n;i++){
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

    // push(ans,0);
    // push(ans,-1);    
    // push(ans,1);
    // push(ans,2);        
    // push(ans,-1);
    // push(ans,3);    
    // push(ans,-1);    
    // roundCounter+=3;
    for(int i=0;i<n;i++){
        if(old[i]!=-1&&new[i]==-1){
            push(ans,i);
        }
    }
    push(ans,-1);
    roundCounter+=1;
    for(int i=0;i<n;i++){
        if(new[i]!=-1&&old[i]!=-1){
            printf("skip v%d %d\n",i,skipCount(i));
        }
    }
    printf("%d\n", roundCounter);
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
