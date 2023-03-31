#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int l;
    int r;
}Node[1000000];

int cmp(node a, node b){
    return a.l<b.l;
}
int main(){
    int n,end,latestStart,ans;
    cin>>n;
    end=n;
    for(int i=0;i<n;i++){
        cin>>Node[i].l>>Node[i].r;
    }
    sort(Node,Node+n,cmp);

    // for(int i=0;i<n;i++){
    //     cout<<Node[i].l<<" "<<Node[i].r<<endl;
    // }
    latestStart=Node[n-1].l;
    ans=1;
    for(int i=n-2;i>=0;i--){
        if(Node[i].r<=latestStart){
            ans++;
            latestStart=Node[i].l;
        }
    }
    cout<<ans<<endl;
}