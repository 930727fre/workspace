#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    struct Queue* next;
    struct Queue* prev;
    int x;
    int y;
}queue;

void pop(queue** current){ 
    *current=(*current)->next;
}

void push_back(int x, int y, queue** front, queue** last, queue** current, int (*visited)[1000]){ // add a element to the back of queue
    visited[x][y]=1; //visited;
    // printf("push_back %d %d\n",x,y);
    if(*last==NULL){ // if the queue is empty, initiate it
        *front=malloc(sizeof(queue));
        (*front)->next=NULL;
        (*front)->prev=NULL;
        *last=*front;
    }
    else{
        (*last)->next=malloc(sizeof(queue));
        (*last)->next->prev=*current;
        *last=(*last)->next;
        (*last)->next=NULL;
    }
    (*last)->x=x;
    (*last)->y=y;   
    return; 
}

bool empty(queue* front){ // check if the queue is empty
    if(front){
        return 0;
    }
    else{
        return 1;
    }
}

void clear(queue* front){ // free the remaining space
    queue* temp;
    while(front!=NULL){
        temp=front->next;      
        free(front);
        front=temp;
    }
}

void sync(int *src2, int deltaX,int deltaY,int (*maze)[1000]){
    if(src2[0]==-1&&src2[1]==-1){
        return;
    }
    else{
        if(maze[src2[0]+deltaX][src2[1]+deltaY]==0){
            src2[0]+=deltaX;
            src2[1]+=deltaY;
            return;
        }
    }
}

int go(int a, int b, int c, int d){
    if(a-c==1){
        return 1;
    }
    else if(a-c==-1){
        return 3;
    }
    else if(b-d==1){
        return 0;
    }
    else if(b-d==-1){
        return 2;
    }
    else{
        return -1;
    }
}

void output(queue* current, int* src2, int (*maze)[1000]){
    if(current->prev!=NULL){
        output(current->prev, src2, maze);
        sync(src2, current->x-current->prev->x, current->y-current->prev->y, maze);
        printf("%d",go(current->x,current->y,current->prev->x, current->prev->y));
        return;
    }
    return;
}

void bfs(int (*src), int (*src2), int (*dst)[2], int maze[1000][1000]){
    int visited[1000][1000];
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            visited[i][j]=0;
        }
    }
    queue *front=NULL, *last=NULL, *current=NULL;
    push_back(src[0], src[1], &front, &last, NULL, visited);
    current=front;
    while(!empty(current)){
        if(current->x==dst[0][0]&&current->y==dst[0][1]){ //if arrive the destination
            // printf("arrive %d %d\n",current->x, current->y);
            dst[0][0]=-1;
            dst[0][1]=-1;
            output(current, src2, maze);
            // printf("\n");
            return;
        }
        else if(current->x==dst[1][0]&&current->y==dst[1][1]){
            // printf("arrive %d %d\n",current->x, current->y);
            dst[1][0]=-1;
            dst[1][1]=-1;
            output(current, src2, maze);
            // printf("\n");
            return;
        }
        else{
            if(maze[current->x+1][current->y]!=1&&visited[current->x+1][current->y]!=1){
                push_back(current->x+1, current->y, &front, &last, &current, visited);
            }
            if(maze[current->x-1][current->y]!=1&&visited[current->x-1][current->y]!=1){
                push_back(current->x-1, current->y, &front, &last, &current, visited);
            }
            if(maze[current->x][current->y+1]!=1&&visited[current->x][current->y+1]!=1){
                push_back(current->x, current->y+1, &front, &last, &current, visited);
            }
            if(maze[current->x][current->y-1]!=1&&visited[current->x][current->y-1]!=1){
                push_back(current->x, current->y-1, &front, &last, &current, visited);
            }
        }
        pop(&current);
    }
}

int main(){
    int n, src[2][2], dst[2][2], maze[1000][1000];
    int nullSrc[]={-1,-1};
    scanf("%d",&n); // input size of the maze
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            scanf("%d",&maze[j][i]); //input the content of maze
        }
    } 
    for(int i=0;i<2;i++){
        scanf("%d %d",&src[i][0],&src[i][1]); //input the source
    }
    for(int i=0;i<2;i++){
        scanf("%d %d",&dst[i][0],&dst[i][1]); //input the destination
    }
    bfs(src[0], src[1], dst, maze);
    bfs(src[1], nullSrc, dst, maze);
    // clear(front);

}