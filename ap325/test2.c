#include <stdio.h>
typedef unsigned long long ULL;

ULL cut(int ,int);
int p[50000],n,l;
int main(){
    scanf("%d %d",&n,&l);
    p[0]=0;
    p[n+1]=l;
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    printf("ans = %llu\n",cut(0,n+1));
}

ULL cut(int left, int right){
    if(right-left==1){
        return 0;
    }
    else{
        int mid=(p[left]+p[right])/2,min=-1,pos=-1;

    }

}