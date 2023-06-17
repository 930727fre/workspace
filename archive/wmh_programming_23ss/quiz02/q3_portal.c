#include <stdio.h>

int maze[11][11];
int n,m,temp;
int traverse(int x, int y){

}

int main(){
    char str[10];

    scanf("%d %d",&n,&m);
    for(int i=0;i<m+2;i++){ // initialize the border
        maze[0][i]=1;
        maze[n+1][i]=1;
    }
    for(int i=0;i<n+2;i++){
        maze[i][0]=1;
        maze[i][m+1]=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        for(int j=1;j<=m;j++){
            maze[i][j]=str[j-1]-'0';
        }
    }
    if(traverse(1,1)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    printMaze();

}