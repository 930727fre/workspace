#include <stdio.h>
#include <limits.h>
int main(){
    int min,max,temp;
    scanf("%d",&temp);
    min=temp;
    max=temp;


    while (1)
    {
        scanf("%d",&temp);
        if(temp==0){
            break;
        }
        else{
            if(temp>max){
                max=temp;
            }
            else if(temp<min){
                min=temp;
            }
        }
    }
    printf("%d",max-min);
    
}