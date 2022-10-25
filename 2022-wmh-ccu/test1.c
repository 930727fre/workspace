#include <stdio.h>

int main(){
    int *a;
    printf("%p\n",*&a);
    printf("%p",*&*&a);
}