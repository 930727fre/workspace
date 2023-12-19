#include <stdio.h>

int main(){
    int input, a,b,c,d;
    scanf("%d", &input);
    d=input%10;
    c=(input%100)/10;
    b=(input%1000)/100;
    a=input/1000;
    d=(d+7)%10;
    c=(c+7)%10;
    b=(b+7)%10;
    a=(a+7)%10;
    printf("%d%d%d%d\n",c,d,a,b);
}