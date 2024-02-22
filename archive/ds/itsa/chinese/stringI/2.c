#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[257];
    int n, length;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", str);
        length=strlen(str);
        for(int i=length-1;i>=0;i--){
                printf("%c", str[i]);
        }
        printf("\n");
    }

}