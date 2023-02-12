#include <iostream>
#include <map>

using namespace std;
int main(){
    map <char, int> myMap;
    myMap.insert(pair<char,int>('a',1));
    myMap.insert(pair<char,int>('b',2));
    // for(map<char,int>::iterator it=myMap.begin();it!=myMap.end();it++){
    //     cout<<it->first<<endl;
    // }
    for(auto it=myMap.begin();it!=myMap.end();it++){
        cout<<it->first<<endl;
    }
}