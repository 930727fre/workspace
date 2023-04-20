#include <stdio.h>

int maze[11][11];
int n,m,temp;
int traverse(int x, int y){
    if(x==n&&y==m){
        return 1;
    }
    else{
        if(maze[x][y]>=2&&maze[x][y]<=9){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(maze[i][j]=maze[x][y]&&i!=x&&j!=y){
                        maze[x][y]=1;
                        if(traverse(i,j)){
                            return 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
            }
        }
        else{
            maze[x][y]=1;
            if(maze[x+1][y]!=1&&traverse(x+1,y)==1){
                return 1;
            }
            else if(maze[x-1][y]!=1&&traverse(x-1,y)){
                return 1;
            }
            else if(maze[x][y+1]!=1&&traverse(x,y+1)){
                return 1;
            }
            else if(maze[x][y-1]!=1&&traverse(x,y-1)){
                return 1;
            }
            else{
                return 0;
            }            

        }
    }
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
    // for(int i=0;i<n+2;i++){
    //     for(int j=0;j<m+2;j++){
    //         printf("%d ",maze[i][j]);
    //     }
    //     printf("\n");
    // }
    if(traverse(1,1)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}