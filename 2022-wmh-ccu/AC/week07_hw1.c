#include <stdio.h>

int main(){
    int n,temp;
    scanf("%d",&n);
    int arr[n][2];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i][0]);
        scanf("%d",&arr[i][1]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][1]>arr[j+1][1]){
                temp=arr[j+1][1];
                arr[j+1][1]=arr[j][1];
                arr[j][1]=temp;

                temp=arr[j+1][0];
                arr[j+1][0]=arr[j][0];
                arr[j][0]=temp;                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][1]==arr[j+1][1]&&arr[j][0]<arr[j+1][0]){
                temp=arr[j+1][0];
                arr[j+1][0]=arr[j][0];
                arr[j][0]=temp;                
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        printf("%d %d\n",arr[i][0],arr[i][1]);
    }
}