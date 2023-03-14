#include <stdio.h>
int arr[100];
int ans=0;
int n,e,quota;
void sort(void);

int main(){
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort();
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            continue;
        }
        else{
            ans++;
            quota=e-arr[i];
            for(int j=i+1;j<n;j++){
                if(quota>=arr[j]){
                    quota-=arr[j];
                    arr[j]=-1;
                }
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