#include <bits/stdc++.h>
using namespace std;
#define max 1000

void dfs(int on, vector<int>(&v)[max], int(&visited)[max]){
    visited[on]=true;
    cout<<on<<endl;
    for(auto i:v[on]){
        if(visited[i]!=true){
            dfs(i, v, visited);
        }
    }
}
int main(){
    vector <int>v[max];
    int visited[max];
    int n,e;
    int tempA, tempB;
    for(int i=0;i<max;i++){
        visited[i]=false;
    }
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>tempA>>tempB;
        v[tempA].push_back(tempB);
    }
    dfs(2, v, visited);
}