#include <bits/stdc++.h>
using namespace std;

int main(){
    int flag=0, i;
    cin>>i;
    for(int j=2;j<=sqrt(i);j++){
        if(i%j==0){
            cout<<"NO"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"YES"<<endl;
    }
    
}