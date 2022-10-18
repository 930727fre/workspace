#include <stdio.h>

int main(){
    int arr[1000000];
    for(int i=0;i<1000000;i++){
        arr[i]=i;
        printf("%d",arr[i]);
    }
}