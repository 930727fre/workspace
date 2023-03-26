#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue <int> que;
vector <int> vec[3050];
int flag=0;
int vis[3050];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int start=1;
    que.push(start);
    vis[start]=1;
    while(!que.empty()){
        for(vector <int>::iterator it=vec[que.front()].begin();it!=vec[que.front()].end();it++){
            if(!vis[*it]){
                que.push(*it);
                vis[*it]=1;
            }
        }
        if(flag){
            cout<<" ";
        }
        else{
            flag=1;
        }
        cout<<que.front();
        que.pop();
    }
    cout<<endl;
}