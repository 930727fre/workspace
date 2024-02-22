#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int ans=0;
    scanf("%s", str);
    for(int i=0;i<strlen(str);i++){
        ans+=(int)(str[i]-'a')+1;
    }
    printf("%d\n", ans);
}