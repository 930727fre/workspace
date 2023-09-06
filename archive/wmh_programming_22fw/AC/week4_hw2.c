#include <stdio.h>

int main(){
    int w,h,upper=1;
    scanf(" %d%d",&w,&h);
    int max=2*w-1,width=w,midSpace=h-2*w;
    for(int a=0;a<h;a++){
        if(upper==1){
            for(int b=0;b<((h-(2*width+midSpace))/2);b++){
                printf(" ");
            }
            if(midSpace>0){
                for(int b=0;b<width;b++){
                    printf("*");
                }
                for(int b=0;b<midSpace;b++){
                    printf(" ");
                }
                for(int b=0;b<width;b++){
                    printf("*");
                }
            }
            else{
                for(int b=0;b<2*width+midSpace;b++){
                    printf("*");
                }
            }

            if(width<max){
                width++;
            }
            midSpace=midSpace-2;
        }
        else{//upper==0
            for(int b=0;b<((h-(2*width+midSpace))/2);b++){
                printf(" ");
            }
            if(midSpace>0){
                for(int b=0;b<width;b++){
                    printf("*");
                }
                for(int b=0;b<midSpace;b++){
                    printf(" ");
                }
                for(int b=0;b<width;b++){
                    printf("*");
                }
            }
            else{
                for(int b=0;b<2*width+midSpace;b++){
                    printf("*");
                }
            }

            if(h==2*width+midSpace){
                width--;
            }
            midSpace=midSpace+2;
        }
        if(2*width+midSpace==2*w-1){
            upper=0;
        }
        printf("\n");
    
    }
    return 0;
}