#include <stdio.h>
int fc(int, int);
int main(){
    int a,b,c,d,ans;
    while(1){
        ans = 0;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(!a&&!b&&!c&&!d){
            break;
        }
        ans+=360*2;
        ans+=9*fc(a,b);
        ans+=360;
        ans+=9*fc(c,b);
        ans+=9*fc(c,d);
        printf("%d\n",ans);
    }
}

int fc(int a, int b){
    if(a>b){
        return a-b;
    }
    else{
        return 40-b+a;
    }
}