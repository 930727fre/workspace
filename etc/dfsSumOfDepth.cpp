#include <iostream>
#include <vector>
using namespace std;
int dfs(int in, int root);
vector <int> tree[1000];
int main(){
    int a,b;
    while(cin>>a>>b){
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cout<<"The sum of depth = "<<dfs(-1,0)<<endl;
}

int dfs(int in,int root){
    int depth=1;
    if(tree[root].size()==1){
        cout<<in<<" "<<root<<" 1"<<endl;
        return 0;
    }
    while(!tree[root].empty()){
        if(in!=tree[root].back()){
            depth+=dfs(root,tree[root].back());
        }
        tree[root].pop_back();
    }
    cout<<in<<" "<<root<<" "<<depth<<endl;

    return depth;
}