#include <stdio.h>
#include <string.h>

void deleteEnter(char*);
int main(){
    FILE *iniFptr,*objFptr,*mskFptr,*bgFptr,*outputFptr;
    char str[1000],buffer[1000];
    char *token;
    iniFptr=fopen("./setting1.ini","r");
    if(iniFptr==NULL){
        printf(".ini doesn't exist\n");
        return 0;
    }
    while(fgets(str,1000,iniFptr)!=NULL){
        //printf("%s",str);
        token=strtok(str,"= ");
        if(!strcmp(token,"OUTPUT")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);
            outputFptr=fopen(token,"w");
            if(outputFptr==NULL){
                printf("output path error\n");
                return -1;
            }
          
        }
        else if(!strcmp(token,"OBJ")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);
            objFptr=fopen(token,"r");
            if(objFptr==NULL){
                printf("obj path error\n");
                return -1;
            }
        }
        else if(!strcmp(token,"MSK")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);
            mskFptr=fopen(token,"r");
            if(mskFptr==NULL){
                printf("msk apth error\n");
                return -1;
            }
        }
        else if(!strcmp(token,"BG")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);              
            bgFptr=fopen(token,"r");
            if(bgFptr==NULL){
                printf("bg path error\n");
                return -1;
            }           
            printf("filename/width/height/XResolution/YResolution\n");
            printf("bg:\n%s/",token);
            fseek(bgFptr,0x26,SEEK_SET);
            fread(buffer,1,4,bgFptr);
            printf("%d/",buffer);
            fseek(bgFptr,0x2A,SEEK_SET);
            fread(buffer,1,1,bgFptr);
            printf("%d",buffer[0]);            
            
            printf("\n");
            printf("obj:\n");
            printf("msk:\n");               
        }

    }
    //檔名、寬度 (Width)、高度 (Height)、橫向解析度 (XResolution)、縱向解析度 (YResolution)

}

void deleteEnter(char* token){
        if(token[strlen(token)-1]=='\n'){
        token[strlen(token)-1]='\0';
    }
}