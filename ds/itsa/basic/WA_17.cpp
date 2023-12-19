#include <bits/stdc++.h>
using namespace std;

int main(){
    int flag=0;
    string str;
    map<string, int> mp;
    while(cin>>str){
        if(mp[str]){
            continue;
        }        
        if(flag){
            cout<<" ";
        }
        else{
            flag=1;
        }
        mp[str]=1;
        for(auto i:str){
            cout<<(char)tolower(i);
        }
    }
    cout<<endl;
}