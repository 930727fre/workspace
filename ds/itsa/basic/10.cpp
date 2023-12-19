#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,temp;
    cin>>a>>b;
    if(a<b){
        temp=b;
        b=a;
        a=temp;
    }
    while(a%b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    cout<<b<<endl;
}