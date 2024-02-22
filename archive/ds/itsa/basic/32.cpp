#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int n;
    cin>>n;
    for(auto i:str){
        if(isalnum(i)){
            if(isalpha(i)){
                if(isalpha(i+n)){
                    cout<<(char)(i+n);
                }
                else{
                    cout<<(char)(i+n-26);
                }
            }
            else{
                if(isalnum(i+n)){
                    cout<<(char)(i+n);
                }
                else{
                    cout<<(char)(i+n-10);
                }                
            }

        }
        else{
            cout<<i;
        }
    }
    cout<<endl;
}