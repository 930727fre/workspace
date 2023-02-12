#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double max,l;
    cin>>n>>l;
    double arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    if(arr[0]>l-arr[n-1]){
        max=arr[0];
    }
    else{
        max=l-arr[n-1];
    }
    for(int i=1;i<n;i++){
        if((arr[i]-arr[i-1])/2.0>max){
            max=(arr[i]-arr[i-1])/2.0;
        }
    }
    cout<<setprecision(10)<<max<<endl;
}