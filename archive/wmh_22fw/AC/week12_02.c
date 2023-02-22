#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int g;
    while(scanf(" %d",&g)!=EOF){
        if(g==0){
            break;
        }
        scanf("%s",str);
        for(int i=0;i<g;i++){
            for(int j=0;j<strlen(str)/g;j++){
                printf("%c",str[(i+1)*(strlen(str)/g)-j-1]);
            }
        }
        printf("\n");
    }
}