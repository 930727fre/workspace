#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char str[1000000];
    int flag=0;
    while(1){
        flag=0;
        fgets(str,1000000,stdin);
        fflush(stdin);
        if(str[0]=='#'){
            break;
        }
        else{
            for(int i=0;i<strlen(str);i++){
                if(isdigit(str[i])){
                    flag=1;
                    printf("%c",str[i]);
                }
                else if(str[i]=='.'){
                    if(isdigit(str[i-1])&&isdigit(str[i+1])){
                        printf("%c",str[i]);
                    }
                }
                else if(str[i]=='+'||str[i]=='-'){
                    if(isdigit(str[i+1])){
                        printf("%c",str[i]);
                    }
                }
                       
            }
        }
        if(!flag){
            printf("No number\n");
        }
        else{
            printf("\n");
        }
    }
    
}