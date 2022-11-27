#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b);
int main(){
    int arr[1000000];
    int n;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

bool cmp(int a, int b){
    if((a%2==0)&&(b%2==0)){
        if(a>b){
            return true;
        }
        else{
            return false;
        }
    }
    else if((a%2==1)&&(b%2==0)){
        return true;
    }
    else if((a%2==0)&&(b%2==1)){
        return false;
    }
    else{
        if(a>b){
            return false;
        }
        else{
            return true;
        }
    }    
}