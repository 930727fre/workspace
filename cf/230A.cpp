#include <iostream>

using namespace std;
int main(){
    long long s,n,temp;
    cin>>s>>n;
    long long arr[n][2];
    int flag=1;
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][0]>arr[j+1][0]||(arr[j][0]==arr[j+1][0]&&arr[j][1]<arr[j+1][1])){
                temp=arr[j][0];
                arr[j][0]=arr[j+1][0];
                arr[j+1][0]=temp;
                temp=arr[j][1];
                arr[j][1]=arr[j+1][1];
                arr[j+1][1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s>arr[i][0]){
            s+=arr[i][1];
        }
        else{
            flag=0;
            cout<<"NO";
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }
}