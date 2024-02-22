#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*input
5
10 5 1 7 4
*/
int main(){
    priority_queue <int, vector<int>, std::greater<int> > pq;
    int n,m;
    long long int ans=0,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        pq.push(m);
    }
    //ans=pq.top();
    temp=pq.top();
    pq.pop();
    //ans=0;
    //cout<<temp<<" "<<ans<<"\n";

    for(int i=1;i<n;i++){
        ans+=temp;
        ans+=pq.top();
        temp+=pq.top();
        pq.pop();
        //cout<<temp<<" "<<ans<<"\n";
    }
    cout<<ans<<endl;

}