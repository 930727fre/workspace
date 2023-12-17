#include <stdio.h>
#include <math.h>

int main(){
    double r, n, p;
    scanf("%lf %lf %lf", &r, &n,&p);
    printf("%d\n",(int)(p*(1+r)*(pow(1+r,n)-1)/(r)));
}