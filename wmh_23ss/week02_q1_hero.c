#include <stdio.h>
typedef long long int LL;
LL n,arr[10000],temp,ans=-1;
LL fc(int t, LL value);
int main(){
    scanf("%llu",&n);
    for(int i=0;i<n;i++){
        scanf("%llu",&arr[i]);
    }
    fc(0,0);
    printf("%lld",temp);

}

LL fc(int t, LL value){

}