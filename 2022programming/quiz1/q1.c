#include <stdio.h>

int main(){
    float a,b,c,delta;
    scanf(" %f%f%f",&a,&b,&c);
    delta=b*b-4*a*c;
    if(delta>0){
        printf("TWO REAL ROOTS");
    }
    else if(delta==0){
        printf("DOUBLE ROOT");
    }
    else{
        printf("TWO COMPLEX ROOTS");
    }
    return 0;
}