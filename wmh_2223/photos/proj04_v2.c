#include <stdio.h>
#include <string.h>

struct {
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

void deleteEnter(char*);
int main(){
    printf("%d",sizeof(bmpinfo));
    FILE *iniFptr,*objFptr,*bgFptr,*mskFptr,*outputFptr;
    char buffer[1000],*token;
    unsigned spec[3][4];
    iniFptr=fopen("setting1.ini","rb");
    while(fgets(buffer,1000,iniFptr)!=NULL){
        token=strtok(buffer," ;");
        deleteEnter(token);      
        if(strstr(token,"OUTPUT")){
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("%s\n",token);
            outputFptr=fopen(token,"wb");
            if(outputFptr==NULL){
                printf("output file path error\n");
                return -1;
            }

        }
        else if(strstr(token,"OBJ")){
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("%s\n",token);
            objFptr=fopen(token,"rb");
            if(objFptr==NULL){
                printf("object file path error\n");
                return -1;
            }
            rewind(objFptr);
            fread(&bmpinfo,1,56,objFptr);
            printf("%d\n",bmpinfo.height);

        } 
        else if(strstr(token,"MSK")){
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("%s\n",token);
            mskFptr=fopen(token,"rb");
            if(mskFptr==NULL){
                printf("mask file path error\n");
                return -1;
            }            
          
        }   
        else if(strstr(token,"BG")){
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("%s\n",token);
            bgFptr=fopen(token,"rb");
            if(bgFptr==NULL){
                printf("background file path error\n");
                return -1;
            }      
                
        }
    }

    fseek(objFptr,0,0);
    fread(&bmpinfo,1,52,objFptr);
    printf("%d\n%d\n%d\n%d\n",bmpinfo.width,bmpinfo.height,bmpinfo.XResolution,bmpinfo.YResolution);


    fclose(objFptr);
    fclose(bgFptr);
    fclose(iniFptr);
    fclose(outputFptr);
    fclose(mskFptr);
}

void deleteEnter(char* token){
    if(token[strlen(token)-1]=='\n'){
        token[strlen(token)-1]='\0';
    }
}