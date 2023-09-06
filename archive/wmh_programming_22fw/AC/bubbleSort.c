#include <stdio.h>

int main(){
    int elements[5]={9,7,1,4,3};
    int i,j,temp;

    for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            if(elements[j]>elements[j+1]){
                temp=elements[j+1];
                elements[j+1]=elements[j];
                elements[j]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",elements[i]);
    }
    
    return 0;
}