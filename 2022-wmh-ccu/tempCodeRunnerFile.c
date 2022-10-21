#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[n,m],ans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[n][m]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            counter=0;
            for(int k=i-1;k<i+2&&k>-1&&k<n;k++){
                for(int l=j-1;l<j+2&&l>-1&&l<m;l++){
                    if(arr[k][l]==1){
                        counter++;
                    }
                }
            }
            ans[n][m]=counter;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }    
    
}