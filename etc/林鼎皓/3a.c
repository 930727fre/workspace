#include <stdio.h>
#include <limits.h>
int main(){
    int arr[110],min=INT_MAX,max=INT_MIN,temp,idx=0;
    while (1)
    {
        scanf("%d",&temp);
        if(temp==0){
            break;
        }
        else{
            arr[idx]=temp;
            idx++;
        }
    }
    for(int i=0;i<idx;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("%d",max-min);
    
}