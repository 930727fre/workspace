#include <stdio.h>
int array[7]={1,3,8,9,12,18,23};

int binarySearch(int sIndex, int eIndex, int target){
    int mIndex=(sIndex+eIndex)/2;

    if(array[mIndex]==target){
        return mIndex;
    }
    else if(array[mIndex]>target){
        return binarySearch(sIndex, mIndex, target);
    }
    else{
        return binarySearch(mIndex+1,eIndex, target);
    }

}

int main(){
    for(int i=0;i<7;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("%d",binarySearch(0,6,23));


}