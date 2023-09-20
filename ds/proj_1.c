#include <stdio.h>

typedef struct Queue{
    struct Queue* next;
    int x;
    int y;
}queue;

int main(){
    int n, src[2][2], dst[2][2], maze[1000][1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    for(int i=0;i<2;i++){
        scanf("%d %d",&src[i][0],&src[i][1]);
    }
    for(int i=0;i<2;i++){
        scanf("%d %d",&dst[i][0],&dst[i][1]);
    }
    
 
}