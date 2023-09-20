#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if(sqrt(x*x+y*y)<=100){
        cout<<"inside"<<endl;
    }
    else{
        cout<<"outside"<<endl;
    }
}