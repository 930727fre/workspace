#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char ini_file_name[10000];
    char ini_file_arr[10000];
    char name_front[10000]="";
    char name_back[10000]="";
    scanf("%s",ini_file_name);
    FILE *fptr = fopen(ini_file_name,"r");
    if(fptr==NULL){
        printf("error");
        return 0;
    }
    while(fscanf(fptr,"%s",ini_file_arr)!=EOF){
        int len = strlen(ini_file_arr);
        for(int i=0;i<len;i++){  
            if(ini_file_arr[i]==';'){
                break;
            }
            int point;
            if(ini_file_arr[i]=='=')
                point = i;
            for(int j=0;j<point;j++)
                strcat(name_front,&ini_file_arr[j]);
            for(int j=point+1;j<len;j++)
                strcat(name_back,&ini_file_arr[j]);
            printf("%s %s",name_front,name_back);
           /* if(!strcmp(name_front,"BG")){
                bg(name_back);
            }*/
        }
    }
}
/*
int bg(int *arr){
    int process[10000];
    FILE *filepointer;
    filepointer = fopen("arr","r");
    fscanf(filepointer,"%s",process);
}*/