#include <stdio.h>

int main(){
    int flag=1;
    FILE *outputFptr,*kingFptr;
    outputFptr=fopen("result1.bmp","rb");
    kingFptr=fopen("FBK.bmp","rb");
    for(int i=0;i<54;i++){
        if(fgetc(outputFptr)!=fgetc(kingFptr)){
            printf("i");
        }
    }
    return 1;
}