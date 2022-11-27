#include <string.h>
#include <stdio.h>

int main () {
    char str[]="\"add\"  \"apple\" 10";
    char *token;
    token=strtok(str,"\"");
    while(token){
        printf("%s %lu\n",token,strlen(token));
        token=strtok(NULL,"\"");
    }
}