#include <stdio.h>
int main(){
    int list[50],length,ans,counter;
    scanf("%d",&counter);
    for(int k=0;k<counter;k++){
        while(scanf("%d",&length)){
            ans=0;
            for(int i=0;i<length;i++){
                scanf("%d",&list[i]);
            }
            for(int i=0;i<length-1;i++){
                for(int j=0;j<length-1-i;j++){
                    if(list[j]>list[j+1]){
                        int temp=list[j+1];
                        list[j+1]=list[j];
                        list[j]=temp;
                        ans++;
                    }
                }
            }
            printf("Optimal train swapping takes %d swaps\n",ans);
        }
    }

}