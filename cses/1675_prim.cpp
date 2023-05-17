#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef long long LL;
using pii=pair<LL, LL>;
vector<pii> vec[100005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool vis[100005];
int main(){
    LL n,m,a,b,c=0,src,counter=0,cost=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(c,b));
        vec[b].push_back(make_pair(c,a));
    }
    src=a;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        pii now=pq.top();
        pq.pop();
        if(vis[now.second]){
            continue;
        }
        else{
            vis[now.second]=1;
            for(auto neighbor:vec[now.second]){
                pq.push(neighbor);
            }
            counter++;
            cost+=now.first;
        }
    }
    if(counter==n){
        cout<<cost;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}