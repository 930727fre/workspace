#include <stdio.h>
#include <string.h>

int isSymbol(char w){
    if(w=='+'||w=='-'||w=='*'||w=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

long long calculate(char* str){
    long long ans=0,temp=1;
    for(int i=0;i<strlen(str);i+=2){
        if(i!=strlen(str)-2){
            if()
        }
        else{
            if()
        }
    }
}

int main(){
    char str[110];
    scanf("%s",&str[1]);
    if(isSymbol(str[1])){
        printf("%lld",calculate(&str[1]));
    }
    else{
        str[0]='+';
        printf("%lld",calculate(str));
    }
}