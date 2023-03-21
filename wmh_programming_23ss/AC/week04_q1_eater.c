#include <stdio.h>
typedef long long LL;
int arr[1000000];
int ans=1;
int n,e,quota;
void sort(void);

int main(){
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quota=e;
    for(int i=0;i<n;i++){
        if(quota>=arr[i]){
            quota-=arr[i];
        }
        else{
            quota=e-arr[i];
            ans++;
        }
    }
    printf("%d",ans);
}

// void sort(void){
//     int temp;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
//     return;
// }