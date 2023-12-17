#include <stdio.h>

int main(){
    int a, b, c;
    for(int i=0;i<999;i++){
        scanf("%d %d %d",&a, &b, &c);
        if(b==c){
            printf("yes");
        }
    }
}