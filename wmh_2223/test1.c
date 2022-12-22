#include <stdio.h>
#include <string.h>
int main(){
    char str[10];
    scanf("%s",str);
    printf("%lu",strspn("a","aeiou"));
}