#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr[3050];
int vis[3050];
int dfs(int);
int flag=1;
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1);
    cout<<endl;
}

int dfs(int now){
    if(!flag){
        cout<<" ";
    }
    flag=0;
    cout<<now;
    vis[now]=1;
    for(vector <int>::iterator it=arr[now].begin();it!=arr[now].end();it++){
        if(!vis[*it]){
            dfs(*it);
        }
    }
    return 0;
}