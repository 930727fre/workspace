#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    fgets(str,1000,stdin);
    printf("%lu",strlen(str));
    

}