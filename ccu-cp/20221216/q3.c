#include <stdio.h>

int main(){
    int n,x,arr[30],ans=0,temp;
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<(1<<n);i++){
        temp=0;
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0){
                temp+=arr[j];
            }
        }
        if(temp==x){
            ans++;
        }
    }
    printf("%d",ans);
}