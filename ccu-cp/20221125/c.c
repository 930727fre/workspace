#include <stdio.h>

int arr[500000];
int binarySearch(int request,int H, int L);
int main(){
    int n,q,request;
    scanf(" %d %d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<q;i++){
        scanf("%d",&request);
        printf("%d\n",binarySearch(request,n-1,0));
    }

}

int binarySearch(int request,int H,int L){

    if(H==L+1){
        if(request==arr[H]){
            return H;
        }
        else if(request==arr[L]){
            return L;
        }
        else{
            return -1;
        }
    }
    else if(request>arr[(H+L)/2]){
        return binarySearch(request,H,(H+L)/2);
    }
    else{
        return binarySearch(request,(H+L)/2,L);
    }
}


/*
5 3 1 2 3 4 5 1 3 5
*/