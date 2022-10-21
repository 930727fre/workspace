#include <stdio.h>

int abs(int m){
    if(m>0){
        return m;
    }
    else{
        return -m;
    }
}

int main(){
    int n,a,b,isJolly;
    while(scanf("%d",&n)!=EOF){
        int arr[n];
        isJolly=1;
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
        scanf("%d",&a);
        for(int i=1;i<n;i++){
            scanf("%d",&b);
            if(isJolly==0){
                continue;
            }
            if(arr[abs(b-a)-1]==1){
                isJolly=0;
            }
            else{
                arr[abs(b-a)-1]=1;
            }
            a=b;
        }
        if(isJolly==1){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");

        }
    }

}