#include <stdio.h>

int main(){
    FILE *fptr;
    char info[54];
    fptr=fopen("FBK.bmp","r");
    fread(info, sizeof(unsigned char), 54, fptr); 
    
    int size=(*(int*)&info[18])*(*(int*)&info[22]);
    printf("size = %x",3*size+54);
}