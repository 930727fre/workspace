#include <stdio.h>
typedef long long int LL;
LL n,arr[10000],temp,ans=-1;
void fc(void);
int main(){
    scanf("%llu",&n);
    for(int i=0;i<n;i++){
        scanf("%llu",&arr[i]);
    }
    fc();

    printf("%lld",ans);

}

void fc(void){
    LL value=arr[0], t=0;
    while(t!=n){
        // printf("%llu %llu\n",t,value);
        if(arr[t+1]<value){
            t++;
            value+=arr[t];
        }
        else if(arr[t+2]<value&&t!=n-2){
            t+=2;
            value+=arr[t];
        }
        else{
            break;
        }
        if(t==n-1){
            if(ans<value){
                ans=value;
            }
        }
    }
}
