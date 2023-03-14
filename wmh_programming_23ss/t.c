#include <stdio.h>
long long ans=0;
int main(){
    int n,e,temp;
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        ans+=temp;
    }
    temp=ans%e;
    ans/=e;
    if(temp){
        printf("%lld",ans+1);
    }
    else{
        printf("%lld",ans);
    }
}