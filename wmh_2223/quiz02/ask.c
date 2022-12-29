#include <stdio.h>
#include <math.h>

int main(){
    unsigned long long dec=0;
    for(int i=0;i<5;i++){
        printf("%d * %10.0f = %.f\n",i,pow(58,4-i),i*pow(58,4-i));
        dec+=i*pow(58,4-i);
    }
}
