#include <stdio.h>

int main(){
    int n,temp=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        int arr[m+1][3];
        for(int j=0;j<m+1;j++){
            for(int k=0;k<2;k++){
                if(j==0){
                    arr[j][k]=0;
                }
                else{
                    scanf("%d",&arr[j][k]);
                }
            }
        }
        /*for(int j=0;j<2;j++){
            for(int k=0;k<m+1;k++){
                printf("%d",arr[k][j]);
            }
            printf("\n");
        }*/
        for(int j=m;j>-1;j--){
            if(arr[j][0]+arr[j][1]+temp>9){
                arr[j][2]=(arr[j][0]+arr[j][1]+temp)%10;
                temp=(arr[j][0]+arr[j][1]+temp)/10;
            }
            else{
                arr[j][2]=arr[j][0]+arr[j][1]+temp;
                temp=0;
            }
        }
        for(int j=0;j<m+1;j++){
            if(j==0&&arr[j][2]==0){
                continue;
            }
            printf("%d",arr[j][2]);
        }
        if(i!=n-1){
            printf("\n\n");
        }
        else{
            printf("\n");
        }
        //printf("\n---\n");

    }
}