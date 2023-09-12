#include <bits/stdc++.h>
using namespace std;
#define max 100

void bfs(int on, vector<int>(&v)[max], int(&visited)[max], queue<int>&q){
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<endl;
        visited[front]=true;
        for(auto i:v[front]){
            q.push(i);
        }
    }

}

int main(){
    vector <int>v[max];
    queue <int>q;
    int visited[max];
    int n, e, tempA, tempB;
    int start=0;
    for(int i=0;i<max;i++){
        visited[i]=false;
    }
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>tempA>>tempB;
        v[tempA].push_back(tempB);
    }
    q.push(start);
    bfs(start, v, visited, q);
}