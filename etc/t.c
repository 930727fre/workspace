#include <string.h>
#include <stdio.h>

int main(){
    char str[]="apple";
    char* ptr;
    ptr=strtok(str, ",");
    printf("%s\n", ptr);
    ptr=strtok(NULL, ",");
    printf("%s", ptr);    
}


