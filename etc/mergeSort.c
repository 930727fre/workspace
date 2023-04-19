#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *arr, int l, int r){
    if(r-l<=1){
        return;
    }
    else{
        int lr, rl, leftIndex=l, rightIndex, tempIndex=0;
        lr=(l+r)/2;
        rl=(l+r)/2+1;
        rightIndex=rl;
        mergeSort(arr, l, lr);
        mergeSort(arr, rl, r);
        int tempArr[r-l+1];
        while(leftIndex!=rl&&rightIndex!=r+1){
            if(arr[leftIndex]>=arr[rightIndex]){
                tempArr[tempIndex++]=arr[rightIndex++];
            }
            else{
                tempArr[tempIndex++]=arr[leftIndex++];
            }
        }
        printf("tempIndex=%d\n",tempIndex);
        while(leftIndex!=rl){
            tempArr[tempIndex++]=arr[leftIndex++];
        }
        while(rightIndex!=r+1){
            tempArr[tempIndex++]=arr[leftIndex++];            
        }
        for(int i=l;i<=r;i++){
            arr[i]=tempArr[l-i];
        }
        return;
    }
}
int main(){
    srand(time(0));
    int *arr, size=rand()%100+1, temp;
    arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        temp=rand()%100+1;
        arr[i]=temp;
        printf("%d ",temp);
    }
    printf("\n");
    mergeSort(arr, 0, size-1);
    printf("after merge sort:\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}