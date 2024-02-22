#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector <int> vec[3050];
int dfs(int);
int arr[3050];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    arr[1]=1;
    if(dfs(1)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

int dfs(int now){
    for(vector<int>::iterator it=vec[now].begin();it!=vec[now].end();it++){
        if(arr[now]==1){
            if(arr[*it]==1){
                return 0;
            }
            else if(arr[*it]==0){
                arr[*it]=2;
                if(!dfs(*it)){
                    return 0;
                }
            }
        }
        else{
            if(arr[*it]==2){
                return 0;
            }
            else if(arr[*it]==0){
                arr[*it]=1;
                if(!dfs(*it)){
                    return 0;
                }
            }            
        }
    }
    return 1;
}