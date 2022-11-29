#include <string.h>
#include <stdio.h>

void strTok(char*);
int main () {
    char str[]="apple com ";
    char *ptr=str;
    printf("%d",strrchr(str,' ')-str);


}