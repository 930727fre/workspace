#include <stdio.h>

int binarySearch(int, int);
int check(int );

int n,k,temp,parameter;
int p[3001];
int main(){

    scanf(" %d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf(" %d",&p[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j]>p[j+1]){
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
            }
        }
    }

    printf("%d\n",binarySearch(1,(p[n-1]-p[0])/k+1));
}

int check(int parameter){
    int index=p[0];
    for(int i=0;i<k;i++){
        index+=parameter;
        if(index>=p[k-1]){
            return 1;
        }
    }
    return 0;
}

int binarySearch(int down, int up){
    if(down+1==up){
        if(check(down)==1){
            return down;
        }
        else{
            return up;
        }
    }    
    if(check((up+down)/2+1)==1){
        return binarySearch((up+down)/2+1,up);
    }
    else{
        return binarySearch(down,(up+down)/2);
    }
}