#include <stdio.h>

int main(){
    int arr[10000];
    int n,ans=0,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                ans++;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }*/
    printf("%d",ans);
}