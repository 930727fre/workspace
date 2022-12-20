#include <stdio.h>

int main(){
    FILE *fptr,*outputFptr;
    fptr=fopen("FBK.bmp","r");
    outputFptr=fopen("result2.bmp","w");
    for(int i=0;i<54;i++){
        fputc(fgetc(fptr),outputFptr);
    }
}