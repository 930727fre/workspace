#include <stdio.h>
#include <stdlib.h>

int *new, *old, *current, *updated, *unionSet;
typedef struct Queue{
    struct Queue *next;
    int n;
}queue;
queue* q;


void push(){

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
    int n;
    scanf("%d",&n);
    new=(int*)calloc(n+2,sizeof(int));
    old=(int*)calloc(n+2,sizeof(int));
    current=(int*)calloc(n+2,sizeof(int));
    updated=(int*)calloc(n+2,sizeof(int));
    unionSet=(int*)calloc(n+2,sizeof(int));
    q=(queue*)malloc(sizeof(queue));
    q->next=NULL;

    for(int i=0;i<n+2;i++){// initialize union set
        unionSet[i]=i;
    }
}
