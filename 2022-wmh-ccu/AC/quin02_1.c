#include <stdio.h>

int main(){
    int m,n;
    scanf(" %d%d",&m,&n);
    long long int matrix[m][n],matrix2[m][n],temp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf(" %lld",&matrix[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf(" %lld",&temp);
            //printf("%d",temp+matrix[i][j]);
            matrix2[i][j]=temp+matrix[i][j];
        }
    }    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%lld",matrix2[i][j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        //if(i!=m-1){
            printf("\n");
        //}
    }    
}

