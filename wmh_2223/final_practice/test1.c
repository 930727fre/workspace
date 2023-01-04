#include <stdio.h>
#include <string.h>

int main(){
    char str[1000]=" apple juice  kamba walker ";
    char *token=&str[1];
    token=strtok(&str[2]," \n");
    printf("%s!\n",token);
    token=strtok(NULL," \n");
    printf("%s!\n",token);
    token=strtok(NULL," \n");
    printf("%s!\n",token);
    token=strtok(NULL," \n");   
    printf("%s!\n",token);
    token=strtok(NULL," \n");   
    printf("%s!\n",token);
    token=strtok(NULL," \n");                
}