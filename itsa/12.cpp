#include <bits/stdc++.h>
using namespace std;

int fn(int n){
    if(n==1||n==0){
        return n+1;
    }
    else{
        return fn(n-1)+fn(n/2);
    }
}

int main(){
    int k;
    cin>>k;
    cout<<fn(k)<<endl;
}