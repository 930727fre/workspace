#include <stdio.h>

int main(){
    int n,ans=0;
    scanf("%d",&n);
    do{
        ans+=n;
        n--;
    }
    while(n);
    printf("%d",ans);
}