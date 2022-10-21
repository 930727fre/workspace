#include <stdio.h>

int main(){
    int n,temp,min=0,distance=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=1;j<n;j++){
                temp=arr[j]-arr[0];
                if(temp<0){
                    temp=-1*temp;
                }
                min+=temp;
            }
        }
        else{
            distance=0;
            for(int j=0;j<n;j++){
                temp=arr[j]-arr[i];
                if(temp<0){
                    temp=temp*(-1);
                }
                distance+=temp;
            }
            if(min>distance){
                min=distance;
            }
        }

    }
    printf("%d",min);
    return 0;

}