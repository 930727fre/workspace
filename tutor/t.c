#include <stdio.h>

int main(){
    int flag=1, i;
    do{
        scanf("%d",&i);
        if(flag==0){
            printf("0");
        }
        else{
            if(i==0){
                flag=0;
                printf("0");
            }
            else{
                printf("1");
            }

        }
    }while(i!=-1);
}
