#include <stdio.h>
#include <stdlib.h>
int n,m;
int race(int, int);
int main(){
    scanf("%d %d",&n,&m);
    printf("%d",race(0,0)/2);
}

int race(int a, int b){
    int count=0;
    if(abs(a-b)>=m){
        // printf("%d %d\n",a,b);
        return 1;
    }
    if(a+b==n){
        // printf("%d %d\n",a,b);
        if(a!=b){
            return 1;
        }
        else{
            return 0;
        }
    }
    count+=race(a+1,b);
    count+=race(a,b+1);
    return count;
}