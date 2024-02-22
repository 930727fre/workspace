#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s, d, max=0;
    int arr[25];
    cin>>n;
    for(int i=0;i<25;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>s>>d;
        for(int j=s;j<d;j++){
            arr[j]++;
        }
    }
    for(int i=0;i<25;i++){
        // cout<<i<<" "<<arr[i]<<endl;
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<max<<endl;
}