#include <stdio.h>
#include <stdlib.h>

/**
 * allocate an m * n matrix (2d dynamic array) and return its address.
 */
int **newMatrix(int m, int n)
{
    int **matrix;
    matrix=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        matrix[i]=(int*)malloc(n*sizeof(int));
    }
    return matrix;
}

/**
 * print the values in the m * n matrix A.
 */
void printMatrix(const int **A, int m, int n)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

/**
 * input the values to the m * n matrix A.
 */
void scanMatrix(int **A, int m, int n)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
}

/**
 * Multiply A (an m * n matrix) by B (an n * r matrix) and return the result (a new 2d dynamic array)
 */
int **mutiMatrix(const int **A, const int **B, int m, int n, int r)
{
    int **C=newMatrix(m,r);
    for(int i=0;i<m;i++){
        for(int j=0;j<r;j++){
            C[i][j]=0;
            for(int k=0;k<n;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return C;
}

/**
 * free A (an m * n matrix)
 */
void freeMatrix(int **A, int m)
{
    for(int i=0;i<m;i++){
        free(A[i]);
    }
    free(A);
}

int main()
{
    int m, n, r, **A, **B, **C;
    scanf("%d%d%d", &m, &n, &r);
    A = newMatrix(m, n);
    B = newMatrix(n, r);
    scanMatrix(A, m, n);
    scanMatrix(B, n, r);
    C = mutiMatrix(A, B, m, n, r);
    puts("-------");
    printMatrix(A, m, n);
    puts("x");
    printMatrix(B, n, r);
    puts("=");
    printMatrix(C, m, r);
    puts("-------");
    freeMatrix(A, m);
    freeMatrix(B, n);
    freeMatrix(C, m);
}