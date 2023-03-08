#include <stdio.h>
int find(int);
int arr[1000000],size[1000000];
int main(){
    int n,m,a,b,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        arr[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        arr[b]=find(a);
        size[b]=0;
    }
    for(int i=0;i<n;i++){
        ans+=size[i];
    }
    for(int i=0;i<n;i++){
        printf("%d ",size[i]);
    }
    printf("\n");
    printf("%d",ans);
}

int find(int n){
    if(arr[n]==n){
        return n;
    }
    else{
        arr[n]=find(arr[n]);
        size[n]=0;
        return arr[n];
    }
}