#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef long long LL;
vector <pair<int, int>> vec[1000000];
priority_queue <pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool vis[1000000];
LL prim(int);
int n,m,u,v,w;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        vec[u].push_back({w,v});
        vec[v].push_back({w,u});
    }
    cout<<prim(u)<<endl;
}

LL prim(int src){
    LL ans=0,counter=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto now=pq.top();
        pq.pop();
        if(vis[now.second]){
            continue;
        }
        else{
            ans+=now.first;
            counter++;
            vis[now.second]=1;
            for(auto neighbor:vec[now.second]){
                pq.push(neighbor);
            }
        }
    }
    if(counter==n){
        return ans;
    }
    else{
        return -1;
    }
}
