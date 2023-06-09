#include <stdio.h>

int main(){
    int n,ans=0;
    scanf("%d",&n);
    while(n){
        ans+=n;
        n--;
    }
    printf("%d",ans);
}