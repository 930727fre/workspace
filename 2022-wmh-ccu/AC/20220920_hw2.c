#include <stdio.h>

int main(){
    unsigned long long  a, b, c, d, e, x;
    scanf("%llu%llu%llu%llu%llu%llu", &x, &a, &b, &c, &d, &e);
    if (x*2<=(a+b+c+d+e)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}