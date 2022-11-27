#include <stdio.h>
#include <string.h>
int main(){
    char str[2000000];
    while(gets(str)){
        for(int i=0;i<strlen(str);i++){
            if(str[i]==' '){
                printf(" ");
            }
            else{
                printf("%c",str[i]-4);
            }
        }
        printf("\n");

    }
}
