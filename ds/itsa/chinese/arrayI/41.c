#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    char *tok;
    int size, num;
    while(fgets(str, 100, stdin)!=NULL){
        size=0;
        num=0;
        tok=strtok(str, " ");
        while(tok!=NULL){
            // printf("%d\n", atoi(tok));
            size++;
            num+=atoi(tok);
            tok=strtok(NULL, " ");
        }
        printf("Size: %d\n",size);
        printf("Average: %.3lf\n",(double)num/size);
    }
}