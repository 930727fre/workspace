#include <iostream>
#include <algorithm>
using namespace std;
struct task{
    int a;
    int d;
}Task[1000000];

int cmp(task a, task b){
    return a.a<b.a;
}
int main(){
    int n;
    long long ans=0,temp=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>Task[i].a>>Task[i].d;
    }
    sort(Task,Task+n,cmp);
    // for(int i=0;i<n;i++){
    //     cout<<Task[i].a<<" "<<Task[i].d<<endl;
    // }
    for(int i=0;i<n;i++){
        temp+=Task[i].a;
        ans+=Task[i].d-temp;
        // cout<<temp<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}