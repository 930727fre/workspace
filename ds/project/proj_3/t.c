#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    struct Link* prev;
    int val;
}link;

link** A;

int main(){
    link *ptr=NULL, *temp;
    A=(link**)malloc(20*sizeof(link*));
    A[7]
}