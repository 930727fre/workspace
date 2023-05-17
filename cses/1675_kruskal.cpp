#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;

struct edge{
    int a;
    int b;
    int weight;
};
struct cmp{
    bool operator()(struct edge a, struct edge b){
        return (a.weight > b.weight);
    }
};

priority_queue<struct edge, vector<struct edge>, cmp> pq;
bool vis[100005];

int main(){
    LL n,m,a,b,c, counter=1,cost=0;
    edge Edge;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>Edge.a>>Edge.b>>Edge.weight;
        pq.push(Edge);
    }
    while(!pq.empty()){
        Edge=pq.top();
        pq.pop();
        if(vis[Edge.a]==1&&vis[Edge.b]==1){
            continue;
        }
        else{
            vis[Edge.a]=1;
            vis[Edge.b]=1;
            cost+=Edge.weight;
            counter++;
        }
    }
    if(counter==n){
        cout<<cost;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}