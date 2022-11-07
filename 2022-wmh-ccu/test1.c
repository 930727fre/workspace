#include <stdio.h>
#include <math.h>

void fc(int b);

int main(){
    int a=1;
    fc(a);
    printf("%d",a);
}

void fc(int b){
    b++;
}