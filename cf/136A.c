#include <stdio.h>

int main(){
    int n;
    int list[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==list[j]-1){
                printf("%d",j+1);
                if(i!=n-1){
                    printf(" ");
                }
                break;
            }
        }
    }
}