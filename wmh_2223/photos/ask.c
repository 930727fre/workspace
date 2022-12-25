#include <stdio.h>
//Q1: sizeof(stuct)
//Q2: char type[2] padding?
struct {
    //char type[2];
    unsigned size;
    char reserved[4];
    unsigned offsetBits;
    unsigned infoSize;
    unsigned width;
    unsigned height;
    short unsigned planes;
    short unsigned bitPerPixel;
    unsigned compression;
    unsigned imageSize;
    unsigned XResolution;
    unsigned YResolution;
    unsigned colors;
    unsigned importantColors;   
}bmpinfo;

int main(){
    printf("size of bmpInfo = %lu\n",sizeof(bmpinfo));
    FILE *kingFptr;
    kingFptr=fopen("KING.bmp","r");
    fseek(kingFptr,0x02,0);
    fread(&bmpinfo,1,54,kingFptr);
    //printf("0x00 = %c\n",bmpinfo.type[0]);
    printf("0x16 = %d\n",bmpinfo.width);
}