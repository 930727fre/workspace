#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
vector<pair<LL,LL>> vec[100005];
bool vis[100005];
LL dis[100005];
priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> pq;
void dijkstra(void);
int main(){
    int n,m,u,v,w;
    int src=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        vec[u].push_back({w,v});
    }
    for(int i=0;i<n;i++){
        dis[i]=1e18;
    }
    dis[src]=0;
    pq.push({0,src});
    dijkstra();
    cout<<"0";
    for(int i=1;i<n;i++){
        cout<<" "<<dis[i];
    }
}

void dijkstra(void){
    while(!pq.empty()){
        if(vis[pq.top().second]){
            pq.pop();
            continue;
        }
        else{
            for(auto [weight, neighbor]:vec[pq.top().second]){
                if(dis[neighbor]>dis[pq.top().second]+weight){
                    dis[neighbor]=dis[pq.top().second]+weight;
                    pq.push({dis[neighbor],neighbor});
                }
            }
            vis[pq.top().second]=1;
            pq.pop();

        }
    }

}