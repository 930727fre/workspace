#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n>=3&&n<=5){
        cout<<"Spring";
    }
    else if(n>=6&&n<=8){
        cout<<"Summer";
    }
    else if(n>=9&&n<=11){
        cout<<"Autumn";
    }
    else if(n==12||n<=2){
        cout<<"Winter";
    }
    cout<<endl;
}