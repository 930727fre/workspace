#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c,d,e,f;
    char word[10];
    scanf("%lf%lf%lf%s%lf%lf%lf", &a, &b, &c, word, &d, &e, &f);
    a=pow(pow(a-d,2)+pow(b-e,2)+pow(c-f,2),0.5);
    printf("%.2lf", a);


}