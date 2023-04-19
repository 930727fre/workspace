#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m,temp;
int maze[12][12],arr[10][2][2];

int traverse(int i, int j){
    printf("tr %d %d\n",i,j);
    if(i==n&&j==m){
        return 1;
    }
    else if(maze[i][j]>=2&&maze[i][j]<=9){
        if(arr[maze[i][j]][0][0]==i&&arr[maze[i][j]][0][1]==j){
            maze[i][j]=1;
            if(traverse(arr[maze[i][j]][1][0],arr[maze[i][j]][1][1])){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            if(traverse(arr[maze[i][j]][0][0],arr[maze[i][j]][0][1])){
                i=arr[maze[i][j]][1][0];
                j=arr[maze[i][j]][1][1];
                arr[maze[i][j]][1][0]=-1;                
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    else{
        maze[i][j]=1;
        if(maze[i+1][j]!=1&&traverse(i+1,j)){
            return 1;
        }
        else if(maze[i-1][j]!=1&&traverse(i-1,j)){
            return 1;
        }
        else if(maze[i][j+1]!=1&&traverse(i,j+1)){
            return 1;
        }
        else if(maze[i][j-1]!=1&&traverse(i,j-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

}
int main(){
    char str[100];
    scanf("%d %d",&n,&m);
    for(int i=0;i<m+2;i++){
        maze[0][i]=1;
        maze[n+1][i]=1;
    }
    for(int i=0;i<n+2;i++){
        maze[i][0]=1;
        maze[i][m+1]=1;
    }
    for(int i=0;i<10;i++){
        arr[i][0][0]=-1;
        arr[i][1][0]=-1;
    }
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        for(int j=1;j<=m;j++){
            int temp=str[j-1]-'0';
            maze[i][j]=temp;
            if(temp>=2&&temp<=9){
                if(arr[temp][0][0]==-1){
                    arr[temp][0][0]=i;
                    arr[temp][0][1]=j;
                }
                else{
                    arr[temp][1][0]=i;
                    arr[temp][1][1]=j;                    
                }

            }
        }
    }

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<10;i++){
        printf("%d %d\n",arr[i][0][0],arr[i][0][1]);
        printf("%d %d\n",arr[i][1][0],arr[i][1][1]);
    }
    if(traverse(1,1)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    
}