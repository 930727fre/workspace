#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%400==0){
        cout<<"Bissextile Year";
    }
    else{
        if(n%100==0){
            cout<<"Common Year";
        }
        else{
            if(n%4==0){
                cout<<"Bissextile Year";
            }
            else{
                cout<<"Common Year";
            }
        }
    }
    cout<<endl;
}