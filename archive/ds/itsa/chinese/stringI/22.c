#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[257];
    int length;
    scanf("%s", str);
    length=strlen(str);
    for(int i=length-1;i>=0;i--){
        if(isalpha(str[i])){
            if(islower(str[i])){
                printf("%c", toupper(str[i]));
            }
            else{
                printf("%c", tolower(str[i]));
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    printf("\n");
}