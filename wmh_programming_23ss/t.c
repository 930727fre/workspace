#include <stdio.h>
typedef long long LL;
int arr[100];
int ans=1;
int n,e,quota;
void sort(void);

int main(){
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[p]);
        arr[p][1]=1;
    }
    sort();
    quota=e;
    for(int i=0;i<n;i++){
        if(!arr[p]){
            continue;
        }
        else{
            if(quota>arr[p]){
                quota-=arr[p];
                arr[p]=0;
            }
        }
    }
    printf("%d",ans);
}

void sort(void){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return;
}