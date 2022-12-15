#include <stdio.h>

int main(){
    FILE *fptr;
    char str[1000];
    char c;
    int i;
    fptr=fopen("./test.txt","r");
    if(fptr==NULL){
        printf("ERROR");
    }
    else{
        c=fgetc(fptr);
        while(!feof(fptr)){
            c=fgetc(fptr);
            printf("%c",c); 
        }

    }
    fclose(fptr);
}