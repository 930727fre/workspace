#include <stdio.h>

int main(){
    int i,flag=1;
    do{
        scanf("%d",&i);
        if(i==-1){  
            break;
        }
        else if(flag==1){
            if(i==1){
                printf("1\n");
            }
            else{
                flag = 0;
                printf("0\n");
            }
        }
        else{
            printf("0\n");
        }
        
    }
    while(1);
}