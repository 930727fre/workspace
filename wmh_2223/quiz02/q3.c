#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char pw[100];
    int counter,capFlag,lowerFlag,charFlag,numFlag,signFlag;

    while(scanf("%s",pw)!=EOF){
        counter=0;
        if(strlen(pw)>=8){
            counter++;
        }
        capFlag=0;
        lowerFlag=0;
        for(int i=0;i<strlen(pw);i++){
            if(isupper(pw[i])){
                capFlag=1;
            }
            else if(islower(pw[i])){
                lowerFlag=1;
            }
        }
        if(capFlag&&lowerFlag){
            counter++;
        }

        charFlag=0;
        numFlag=0;
        signFlag=0;

        for(int i=0;i<strlen(pw);i++){
            if(isupper(pw[i])||islower(pw[i])){
                charFlag=1;
            }
            else if(isdigit(pw[i])){
                numFlag=1;
            }
            else if(isgraph(pw[i])){
                signFlag=1;
            }            
        }

        if(charFlag&&(numFlag||signFlag)){
            counter++;
        }
        if(counter==3){
            printf("This password is STRONG\n");
        }
        else if(counter==2){
            printf("This password is GOOD\n");
        }
        else if(counter==1){
            printf("This password is ACCEPTABLE\n");
        }
        else{
            printf("This password is WEAK\n");
        }

    }
}