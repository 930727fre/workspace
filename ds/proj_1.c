#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    struct Queue* next;
    int x;
    int y;
}queue;

void pop(queue** front){ // clear the frontmost element
    queue* temp=(*front)->next;
    free(*front);
    *front=temp;
}

void push_back(int x, int y, queue** front, queue** last, int (*maze)[1000]){ // add a element to the back of queue
    maze[x][y]=1; //visited;
    printf("push_back %d %d\n",x,y);
    if(*last==NULL){ // if the queue is empty, initiate it
        *front=malloc(sizeof(queue));
        (*front)->next=NULL;
        *last=*front;
    }
    else{
        (*last)->next=malloc(sizeof(queue));
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


void bfs(int src[1][2], int dst[1][2], int maze[1000][1000]){
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    queue *front, *last, *current;
    push_back(src[0][1], src[0][0], &front, &last, maze);
    while(!empty(front)){
        current=front;
        if(current->x==dst[0][1]&&current->y==dst[0][0]){ //if arrive the destination
            printf("arrived %d %d\n", current->x, current->y);
            clear(front);
            return;
        }else{
            if(maze[current->x+1][current->y]!=1){
                push_back(current->x+1, current->y, &front, &last, maze);
            }
            if(maze[current->x-1][current->y]!=1){
                push_back(current->x-1, current->y, &front, &last, maze);
            }
            if(maze[current->x][current->y+1]!=1){
                push_back(current->x, current->y+1, &front, &last, maze);
            }
            if(maze[current->x][current->y-1]!=1){
                push_back(current->x, current->y-1, &front, &last, maze);
            }
        }
        pop(&front);
    }
    
}

int main(){
    int n, src[2][2], dst[2][2], maze[1000][1000];
    scanf("%d",&n); // input size of the maze
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&maze[i][j]); //input the content of maze
        }
    }
    for(int i=0;i<2;i++){
        scanf("%d %d",&src[i][0],&src[i][1]); //input the source
    }
    for(int i=0;i<2;i++){
        scanf("%d %d",&dst[i][0],&dst[i][1]); //input the destination
    }
    bfs(src, dst, maze);
    // bfs(&src[1], &dst[1], maze);
}