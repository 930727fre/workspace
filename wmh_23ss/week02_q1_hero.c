#include <stdio.h>
typedef long long int LL;
LL n,arr[10000],temp,ans=-1;
void fc(int t, LL value);
int main(){
    scanf("%llu",&n);
    for(int i=0;i<n;i++){
        scanf("%llu",&arr[i]);
    }
    fc(1,arr[0]);
    fc(2,arr[0]);
    printf("%lld",ans);

}

void fc(int t, LL value){
    if(value>arr[t]){
        value+=arr[t];
        // printf("%d %llu\n",t,value);
        if(t==n-1){
            if(value>ans){
                ans=value;
                // printf("hi\n");
            }
            return;
        }
        else{
            fc(t+1,value);
            if(t!=n-2){
                fc(t+2,value);
            }
        }
    }   
    else{
        return;
    } 
}
