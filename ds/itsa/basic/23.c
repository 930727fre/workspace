#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, a1, a2, a3;
    int b1, b2, b3;
    char str[1000];
    char* tok;
    scanf("%s", str);
    tok=strtok(str, ",");
    n=atoi(tok);
    tok=strtok(NULL, ",");
    a1=atoi(tok);
    tok=strtok(NULL, ",");
    a2=atoi(tok);
    tok=strtok(NULL, ",");
    a3=atoi(tok);        
    if(n<a1*15+ a2*20+ a3*30){
        printf("0\n");
        return 0;
    }
    else{
        n-=a1*15+ a2*20+ a3*30;
        b3=n/50;
        n%=50;
        b2=n/5;
        n%=5;
        b1=n;
        printf("%d,%d,%d\n",b1,b2,b3);
    }
}