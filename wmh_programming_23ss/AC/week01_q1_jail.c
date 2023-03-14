#include <stdio.h>
char arr[21][21];
int n,m;
int travel(int, int),counter=0;
void p(void);
int main(){
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
    // p();
    if(travel(0,0)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    //p();
    // printf("\ncounter = %d",counter);    
}
int travel(int x, int y){// 0left 1up 2 right 3down
    counter++;
    arr[x][y]='1';
    if(x==n-1&&y==m-1){
        return 1;
    }
    if(arr[x+1][y]=='0'&&x+1!=n){
        if(travel(x+1,y)){
            return 1;
        }
    }
    if(arr[x-1][y]=='0'&&x!=0){
        if(travel(x-1,y)){
            return 1;
        }
    }
    if(arr[x][y+1]=='0'&&y+1!=m){
        if(travel(x,y+1)){
            return 1;
        }
    }
    if(arr[x][y-1]=='0'&&y!=0){
        if(travel(x,y-1)){
            return 1;
        }
    }
    return 0;
}
void p(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}