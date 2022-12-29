#include <stdio.h>
#include <string.h>

FILE *iniFptr,*objFptr,*bgFptr,*mskFptr,*outputFptr;// file pointer for each .ini/ object/ background/ mask/ output file
struct {//store the file info in struct
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
int fc(void);
void deleteEnter(char*);// delete '\n' at the end of string
int main(){
    char buffer[1000],*token;
    unsigned spec[3][4];// record width/height/xresolution/yresolution of each file
    int index;
    printf("Please input the path of .ini.\n>>");
    scanf("%s",buffer);
    iniFptr=fopen(buffer,"rb");
    if(iniFptr==NULL){
        printf("The path of .ini is invalid.");
        return -1;
    }
    else{
        printf("spec: width/ height/ xResolution/ yResolution\n");
    }
    while(fgets(buffer,1000,iniFptr)!=NULL){//extract the path from .ini
        token=strtok(buffer," ;");
        deleteEnter(token);      
        if(strstr(token,"OUTPUT")){
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("output: %s\n",token);
            outputFptr=fopen(token,"wb");
            if(outputFptr==NULL){
                printf("output file path error\n");
                return -1;
            }
        }
        else if(strstr(token,"OBJ")){//extract obj path from input
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("obj:\n%s: ",token);
            objFptr=fopen(token,"rb");
            if(objFptr==NULL){
                printf("object file path error\n");
                return -1;
            }
            fseek(objFptr,2,0);
            fread(&bmpinfo,1,52,objFptr);
            printf("%d/ %d/ %d/ %d\n",bmpinfo.width,bmpinfo.height,bmpinfo.XResolution,bmpinfo.YResolution);
            spec[0][0]=bmpinfo.width;
            spec[0][1]=bmpinfo.height;
            spec[0][2]=bmpinfo.XResolution;
            spec[0][3]=bmpinfo.YResolution;
        } 
        else if(strstr(token,"MSK")){//extract msk path from input
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("MSK:\n%s: ",token);
            mskFptr=fopen(token,"rb");
            if(mskFptr==NULL){
                printf("mask file path error\n");
                return -1;
            }  
            fseek(mskFptr,2,0);
            fread(&bmpinfo,1,52,mskFptr);
            printf("%d/ %d/ %d/ %d\n",bmpinfo.width,bmpinfo.height,bmpinfo.XResolution,bmpinfo.YResolution);
            spec[1][0]=bmpinfo.width;
            spec[1][1]=bmpinfo.height;
            spec[1][2]=bmpinfo.XResolution;
            spec[1][3]=bmpinfo.YResolution;                      
          
        }   
        else if(strstr(token,"BG")){//extract bg path from input
            token=strtok(buffer,"=");
            token=strtok(NULL,"=");
            printf("BG:\n%s: ",token);
            bgFptr=fopen(token,"rb");
            if(bgFptr==NULL){
                printf("background file path error\n");
                return -1;
            }
            fseek(bgFptr,2,0);
            fread(&bmpinfo,1,52,bgFptr);
            printf("%d/ %d/ %d/ %d\n",bmpinfo.width,bmpinfo.height,bmpinfo.XResolution,bmpinfo.YResolution);
            spec[2][0]=bmpinfo.width;
            spec[2][1]=bmpinfo.height;
            spec[2][2]=bmpinfo.XResolution;
            spec[2][3]=bmpinfo.YResolution;
        }
    }
    if(spec[0][0]!=spec[1][0]||spec[0][1]!=spec[1][1]){//foolproof of width and height
        printf("The size of object and mask aren't same.\n");
        return -1;
    }
    if(spec[0][0]!=spec[2][0]||spec[0][1]!=spec[2][1]){
        printf("The size of object and background aren't same.\n");
        return -1;        
    }
    rewind(objFptr);
    for(int i=0;i<54;i++){
        fputc(fgetc(objFptr),outputFptr);//copy the first 54 bytes
    }
    index=0;
    for(int i=0;i<spec[0][1];i++){
        for(int j=0;j<spec[0][0]||index%4!=0;j++){
            for(int k=0;k<3;k++){
                if(j>=spec[0][0]){//padding if index%4!=0
                    fputc(0,outputFptr);
                    fgetc(bgFptr);
                    fgetc(objFptr);
                    fgetc(mskFptr);
                }
                else{
                    fputc(fc(),outputFptr);//fill the output byte by the pixel given
                }
            }

        }
    }
    fclose(objFptr);
    fclose(bgFptr);
    fclose(iniFptr);
    fclose(outputFptr);
    fclose(mskFptr);
    printf("Process end\n");
}

void deleteEnter(char* token){
    if(token[strlen(token)-1]=='\n'){
        token[strlen(token)-1]='\0';
    }
}

int fc(void){
    int o=fgetc(objFptr),b=fgetc(bgFptr),m=fgetc(mskFptr);
    return b*m/255+o*(255-m)/255;
}