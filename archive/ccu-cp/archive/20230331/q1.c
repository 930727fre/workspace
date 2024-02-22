#include <stdio.h>

int main(){
    int q,a,ans;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        ans=0;
        scanf("%d",&a);
        if(a>=100){
            ans+=a/100;
            a=a%100;
        }
        if(a>=50){
            ans+=a/50;
            a=a%50;
        }
        if(a>=10){
            ans+=a/10;
            a=a%10;
        } 
        if(a>=5){
            ans+=a/5;
            a=a%5;
        }
        if(a>=1){
            ans+=a/1;
            a=a%1;
        }
        printf("%d\n",ans);
    }
}