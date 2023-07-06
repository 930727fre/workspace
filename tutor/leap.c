#include <stdio.h>

int main(){
    int i;
    scanf("%d",&i);
    if(i%4 !=0){
        printf("No\n");
    }
    else
        if(i%100!=0){
            printf("No\n");
        }
        else
            if(i%400==0){
                printf("No\n");

        }
            else
            printf("Yes\n");
}