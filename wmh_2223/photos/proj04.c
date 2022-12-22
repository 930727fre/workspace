#include <stdio.h>
#include <string.h>

void deleteEnter(char*);
int fc(int);
FILE *iniFptr,*objFptr,*mskFptr,*bgFptr,*outputFptr;

int main(){
    char str[1000],buffer[1000];
    char *token;
    int request[4]={0x12,0x16,0x26,0x2A},spec[3][4],index;
    iniFptr=fopen("./setting2.ini","r");
    if(iniFptr==NULL){
        printf(".ini doesn't exist\n");
        return 0;
    }
    printf("filename/width/height/XResolution/YResolution\n");

    while(fgets(str,1000,iniFptr)!=NULL){
        //printf("%s",str);
        token=strtok(str,"= ");
        if(!strcmp(token,"OUTPUT")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);
            printf("OUTPUT:\n%s\n",token);
            outputFptr=fopen(token,"w+");
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
            printf("OBJ:\n%s/",token);
            for(int i=0;i<4;i++){
                fseek(objFptr,request[i],SEEK_SET);
                fread(buffer,4,1,objFptr);      
                spec[0][i]=*(int*)&buffer;
                printf("%d",*(int*)&buffer);
                if(i!=3){
                    printf("/");
                }
            }
            printf("\n");            
        }
        else if(!strcmp(token,"MSK")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);
            mskFptr=fopen(token,"r");
            if(mskFptr==NULL){
                printf("msk apth error\n");
                return -1;
            }
            printf("MSK:\n%s/",token);
            for(int i=0;i<4;i++){
                fseek(mskFptr,request[i],SEEK_SET);
                fread(buffer,4,1,mskFptr);          
                spec[1][i]=*(int*)&buffer;
                printf("%d",*(int*)&buffer);
                if(i!=3){
                    printf("/");
                }
            }
            printf("\n");
        }
        else if(!strcmp(token,"BG")){
            token=strtok(NULL,"= ;");
            deleteEnter(token);              
            bgFptr=fopen(token,"r");
            if(bgFptr==NULL){
                printf("bg path error\n");
                return -1;
            }           
            printf("BG:\n%s/",token);
            for(int i=0;i<4;i++){
                fseek(bgFptr,request[i],SEEK_SET);
                fread(buffer,4,1,bgFptr);          
                spec[2][i]=*(int*)&buffer;
                printf("%d",*(int*)&buffer);
                if(i!=3){
                    printf("/");
                }
            }
            printf("\n");
             
        }

    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ",spec[i][j]);
        }
        printf("\n");
    }
    if(spec[0][0]!=spec[1][0]||spec[0][1]!=spec[1][1]){
        printf("The size of object and mask aren't same.\n");
        return -1;
    }
    if(spec[0][0]!=spec[2][0]||spec[0][1]!=spec[2][1]){
        printf("The size of object and background aren't same.\n");
        return -1;        
    }
    rewind(bgFptr);
    for(int i=0;i<54;i++){
        char c = fgetc(bgFptr);
        fputc(c,outputFptr);
    }
    index=0;
    for(int i=0;i<spec[0][1];i++){
        for(int j=0;j<spec[0][0]||index%4!=0;j++){
            for(int k=0;k<3;k++){
                if(j>=spec[0][0]){
                    fputc(0x00,outputFptr);
                }
                else{
                    fputc(fc(index),outputFptr);
                }
                index++;
            }
        }
    }
    fclose(iniFptr);
    fclose(objFptr);
    fclose(mskFptr);
    fclose(bgFptr);
    fclose(outputFptr);
}

void deleteEnter(char* token){
        if(token[strlen(token)-1]=='\n'){
        token[strlen(token)-1]='\0';
    }
}

int fc(int index){
    /*char buffer[1000];
    fseek(objFptr,index+54,SEEK_SET);
    fread(buffer,4,1,objFptr);      
    int o = *(int*)&buffer;  
    fseek(mskFptr,index+54,SEEK_SET);
    fread(buffer,4,1,mskFptr);      
    int m = *(int*)&buffer; 
    fseek(bgFptr,index+54,SEEK_SET);
    fread(buffer,4,1,bgFptr);      
    int b = *(int*)&buffer;  
    if(index<3){
        printf("o %d /b %d /m %d\n",o,b,m);
    }*/
    int o=fgetc(objFptr),b=fgetc(bgFptr),m=fgetc(mskFptr);

    return b*m/255+o*(255-m)/255;
}