#include <stdio.h>

union number {
    float f;
    int i;
    int p;
};
int main(){
    union number n;
    n.i=3;
    printf("%d",n.p);

}