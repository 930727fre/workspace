#include <stdio.h>

int main(){
    int n,arr[10050],temp,min,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n/2;i++){
        arr[i]=arr[i]+arr[n-1-i];
    }
    min=arr[0];
    max=arr[0];
    for(int i=1;i<n/2;i++){
        if(min>arr[i]){
            min=arr[i];
        }
        if(max<arr[i]){
            max=arr[i];
        }
    }
    printf("%d %d\n",min,max);
}