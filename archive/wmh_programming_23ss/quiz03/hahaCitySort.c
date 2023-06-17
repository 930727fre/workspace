#include <stdio.h>

int main(){
    int arr[201][101], n, a, k, flag=0;
    for(int i=0;i<201;i++){
        for(int j=0;j<101;j++){
            arr[i][j]=0;
        }
    }
    scanf("%d", &n);
    for(int i=0;i<n;i++){// a for year 
        scanf("%d %d",&a, &k);
        arr[a][k]++;
    }
    for(int i=0;i<201;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<arr[i][j];k++){
                if(flag==0){
                    flag=1;
                }
                else{
                    printf(" ");
                }
                printf("%d",j);

            }
        }
    }
    printf("\n");
}