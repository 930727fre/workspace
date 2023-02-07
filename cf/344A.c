#include <stdio.h>

int main(){
    int n,prev=0,m,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        if(prev!=m){
            ans++;
        }
        prev=m;
    }
    printf("%d",ans);

}