#include <bits/stdc++.h>
using namespace std;

void split(string str, string pattern){
    int ans=0;
    int temp=str.find(pattern);
    while(temp!=string::npos){
        ans++;
        str=str.substr(temp+1);
        temp=str.find(pattern);
    }
    cout<<ans<<endl;
}

int main(){
    string pattern, str;
    cin>>pattern>>str;
    split(str, pattern);
}