#include <stdio.h>

int main(){
    int a, b, ans=0;
    scanf("%d%d",&a, &b);
    if(a%2==0){
        a+=1;
    }
    if (b%2==0)
    {
        b-=1;
    }
    
    while(a<=b){
        ans+=a;
        a+=2;
    }
    printf("%d", ans);
    return 0;
    
};