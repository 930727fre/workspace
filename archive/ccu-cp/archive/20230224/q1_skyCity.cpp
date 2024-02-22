#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,q;
vector <int> arr[3050];
int main(){
    cin>>n>>m>>q;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        cin>>a;
        sort(arr[a].begin(),arr[a].end());
        for(vector <int>::iterator it=arr[a].begin();it!=arr[a].end();it++){
            if(it!=arr[a].begin()){
                cout<<" ";
            }
            cout<<*it;
        }
        cout<<endl;
    }
}