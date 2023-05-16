#include <stdio.h>

int main(){
    long long n, c, arr[10], index, num, temp;
    scanf("%lld",&c);
    for(int i=0;i<c;i++){
        index=9;
        for(int j=0;j<10;j++){
            arr[j]=-1;
        }
        scanf("%lld",&n);
        for(int j=0;j<n;j++){
            scanf("%lld", &num);
            if(arr[0]==-1){
                arr[index]=num;
                if(index==0){
                    for(int k=0;k<10;k++){
                        if(arr[k]<arr[index]){
                            index=k;
                        }
                    }
                }
                else{
                    index--;
                }
            }
            else{
                if(arr[index]<num){
                    arr[index]=num;
                }
                for(int k=0;k<10;k++){
                    if(arr[k]<arr[index]){
                        index=k;
                    }
                }
            }
        }
        for(int j=0;j<10;j++){
            for(int k=0;k<9-j;k++){
                if(arr[k]<arr[k+1]){
                    temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }
        for(int j=0;j<n&&j<10;j++){
            printf("%lld",arr[j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}