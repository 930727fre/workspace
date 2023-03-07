#include <stdio.h>
#include <stdlib.h>

int **fc(void){
    int **matrix;
    matrix=(int**)malloc(5*sizeof(int*));
    matrix[0]=(int*)malloc(1);
    matrix[0][0]=3;
    return matrix;
}
int main(){
    int **matrix=fc();
    printf("%d",matrix[0][0]);

    
}