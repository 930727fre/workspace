#include <bits/stdc++.h>
using namespace std;

int palindrome(string& str){
    int flag =1;
    for(int i=0;i<str.length();i++){
        if(str[i]!=str[str.length()-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    string str;
    cin>>str;
    if(palindrome(str)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}