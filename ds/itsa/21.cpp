#include <bits/stdc++.h>
using namespace std;

int main(){
    float min=INT_MAX, max=INT_MIN, n;
    for(int i=0;i<10;i++){
        cin>>n;
        if(min>n){
            min=n;
        }
        if(max<n){
            max=n;
        }
    }
    cout<<"maximum:"<<fixed<<setprecision(2)<<max<<endl;
    cout<<"minimum:"<<fixed<<setprecision(2)<<min<<endl;
}