#include <stdio.h>
#include <stdlib.h>

void fn(int arr[2][3]){
    arr[0][0]=99;
}

int main(){
    int arr[2][3];
    fn(arr);
    printf("%d", arr[0][0]);
}