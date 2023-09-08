#include <stdio.h>


int swap(char*, int, int);
int permutate(char*, int, int);
int main(){
    char arr[]={'a','b','c','d','e'};
    permutate(arr, sizeof(arr),0);
}

int permutate(char* arr, int size, int index){
    if(index==size){
        for(int i=0;i<size;i++){
            printf("%c",arr[i]);
        }
        printf("\n");
        return 0;
    }
    for(int i=index;i<size;i++){
        swap(arr, index,i);
        permutate(arr, size, index+1);
        swap(arr, index,i);
    }
}
int swap(char* arr, int a, int b){
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
