#include <stdio.h>
int n,k,arr[100000];
int bs(int, int);
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bs(0,n-1);
}

int bs(int down, int low){
    
}