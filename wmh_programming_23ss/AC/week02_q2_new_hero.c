#include <stdio.h>
typedef long long int LL;
LL n,arr[100000];
int fc(void);
int main(){
    scanf("%llu",&n);
    for(int i=0;i<n;i++){
        scanf("%llu",&arr[i]);
    }
    if(fc()){
        printf("%llu\n",arr[n-1]);
    }
    else{
        printf("%d\n",-1);
    }
    // for(int i=0;i<n;i++){
    //     printf("%llu ",arr[i]);
    // }
}

int fc(void){
    LL t=2;
    arr[1]=arr[0]-arr[1];
    if(arr[1]<=0){
        return 0;
    }
    while(t!=n){
        if(arr[t-1]>arr[t-2]){
            arr[t]=arr[t-1]-arr[t];
        }
        else{
            arr[t]=arr[t-2]-arr[t];
        }
        // printf("%llu %llu\n",t,arr[t]);
        if(arr[t]<=0&&arr[t-1]<=0){
            return 0;
        }

        if(t==n-1&&arr[t]>0){
            if(arr[t]>0){
                return 1;
            }
            else{
                return 0;
            }
        }
        t++;
    }
    return 0;
}
//     1 1 0 1