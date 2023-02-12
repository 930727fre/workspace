#include <iostream>
#include <algorithm>
using namespace std;
int cmp(double a,double b){
    if(a>b){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    double n,l,temp;
    double max;
    cin>>n>>l;
    double arr[(int)l];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+(int)n);
    max=arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]-arr[i-1])/2>max){
            max=(arr[i]-arr[i-1])/2;
        }
    }
    if(l-arr[(int)n-1]>max){
        max=l-arr[(int)n-1];
    }
    cout<<max;
}