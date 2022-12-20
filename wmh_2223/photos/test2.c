#include <stdio.h>

int main(){
    FILE *fptr;
    fptr=fopen("FBk.bmp","w+");
    //fseek(fptr,5,SEEK_END);
    //fwrite("apple",1,10,fptr);
    for(int i=0;i<10;i++){
        fputc(i,fptr);
    }
    fclose(fptr);
}
