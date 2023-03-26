#include <stdio.h>
#include <string.h>

int main(){
    int n,q,index,address,value;
    int arr[1000000000][2];
    char cmd[5]="";
    scanf(" %d%d",&n,&q);
    //printf("ejfo");
    for(int i=0;i<n;i++){
        scanf(" %d",&arr[i][0]);
    }
    for(int i=0;i<n;i++){
        scanf(" %d",&arr[i][1]);
    }
    for(int i=0;i<q;i++){
        scanf(" %s",cmd);
        scanf(" %d",&address);        
        if(cmd[0]=='A'){
            scanf(" %d",&value);
            for(int j=0;j<n;j++){
                if(arr[j][1]==address){
                    arr[j][0]=arr[j][0]+value;
                    break;
                }
            }
        }
        else if(cmd[0]=='U'){
            scanf(" %d",&value);
            for(int j=0;j<n;j++){
                if(arr[j][1]==address){
                    arr[j][0]=value;
                    break;
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(arr[j][1]==address){
                    printf("%d\n",arr[j][0]);
                }
            }
        }
    }
}