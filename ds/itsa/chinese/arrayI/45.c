#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    while(fgets(str, 1000, stdin)!=NULL){
        if(strstr(str, "\n")){
            printf("There are %lu characters\n", strlen(str)-1);
        }
        else{
            printf("There are %lu characters\n", strlen(str));
        }
    }
}