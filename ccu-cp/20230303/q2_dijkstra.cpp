#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
vector<pair<LL,LL>> vec[100005];
int par[100005],fc(int);
bool vis[100005];
LL dis[100005];
priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> pq;
void dijkstra(void);
int step=0;
int n,m,u,v,w,temp;

int main(){
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
    fc(n-1);
    
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
                    par[neighbor]=pq.top().second;
                }
            }
            vis[pq.top().second]=1;
            pq.pop();

        }
    }

}

int fc(int p){
    step++;
    if(p==0){
        cout<<dis[n-1]<<" "<<step<<endl<<1;
    }
    else{
        fc(par[p]);
        cout<<" "<<p+1;
    }
    return 0;
}