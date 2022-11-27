#include <stdio.h>

int main(){
    int n,m,ans=0,temp;
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp>=m){
            ans+=(temp/m);
        }
    }
    printf("%d",ans);
}