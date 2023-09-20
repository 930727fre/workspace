#include <bits/stdc++.h>
using namespace std;

vector<int> split(string, char);
int main(){
    string str="hello world";
    auto splited=split(str, 'q');
    for(auto i:splited){
        cout<<i<<endl;
    }
}

vector<int> split(string str, char pattern){
    vector<int> v;
    int pos=str.find(pattern);
    while(pos!=npos){

    }
    return v;
}