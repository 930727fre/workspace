#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int*, int, int, int);
int main(){
    int size=7, arr[7]={0,1,3,5,7,9,11};

    printf("%d", binarySearch(arr, 4,0, size-1));

}

int binarySearch(int* arr, int target, int l,int r){
    int mid=l+(r-l)/2;
    if(l>r){
        return -1;
    }
    else if(target==arr[mid]){
        return mid;
    }
    else if(target<arr[mid]){
        return binarySearch(arr, target, l, mid-1);
    }
    else if(target>arr[mid]){
        return binarySearch(arr, target, mid+1,r);
    }
}
