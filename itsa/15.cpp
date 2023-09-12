#include <bits/stdc++.h>
using namespace std;

void split(vector<string>& v, string str, string pattern){
    int begin=0;
    int end=str.find(pattern);
    cout<<end<<endl;
    while(end!=string::npos){
        if(end!=begin){//preventing consecutive occuence of pattern
            cout<<str.substr(begin, end)<<endl;
            v.push_back(str.substr(begin, end));
        }
        begin=end+pattern.size();
        end=str.find(pattern, begin);
    }
    if(begin!=str.length()){
        cout<<str.substr(begin)<<endl;
        v.push_back(str.substr(begin));
    }
}

int main(){
    string str;
    vector<string> v;
    string pattern=" ";
    cin>>str;
    split(v, str, pattern);
    cout<<"---"<<endl;
    for(auto i:v){
        cout<<i<<endl;
    }
    
}