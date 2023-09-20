#include <bits/stdc++.h>
using namespace std;

void split(vector<string>& v, string str, string pattern){
    int begin=0;
    int end=str.find(pattern);
    while(end!=string::npos){
        if(end!=begin){//preventing consecutive occuence of pattern
            v.push_back(str.substr(begin, end-begin));
        }
        begin=end+pattern.size();
        end=str.find(pattern, begin);
    }
    if(begin!=str.length()){
        v.push_back(str.substr(begin));
    }
}

int main(){
    string str;
    vector<string> v;
    string pattern=" ";
    int ans[26];
    getline(cin, str);
    split(v, str, pattern);
    cout<<v.size()<<endl;
    for(int i=0;i<26;i++){
        ans[i]=0;
    }
    for(auto i:v){
        for(int j=0;j<i.size();j++){
            ans[tolower(i[j])-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        if(ans[i]){
            cout<<(char)(i+'a')<<" : "<<ans[i]<<endl;
        }
    }
    
}