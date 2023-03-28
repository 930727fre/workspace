#include <stdio.h>

int n,m,basket[1000],e,ans,temp;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&basket[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(basket[j]>basket[j+1]){
                temp=basket[j];
                basket[j]=basket[j+1];
                basket[j+1]=temp;
            }
        }
    }
    for(int i=0;i<m;i++){
        ans=0;
        scanf("%d",&e);
        for(int j=n-1;j>=0;j--){
            if(e>=basket[j]){
                ans+=e/basket[j];
                printf("%d %d %d\n",e,basket[j],ans);
                e=e%basket[j];
            }
        }
        printf("%d\n",ans);
    }
}