#include <stdio.h>

int main(){
    int i;
    while(1){
        scanf("%d",&i);
        if(i%4 !=0){
            printf("No\n");
        }
        else 
            if(i%100!=0){
                printf("Yes\n");
            }
            else
                if(i%400 == 0){
                printf("Yes\n");
                }
                else
                printf("No\n");
            }
    }
