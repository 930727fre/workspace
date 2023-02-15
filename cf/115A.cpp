#include <iostream>
using namespace std;
int main(){
    int ans=0,level,temp,n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        temp=i;
        level=1;
        while(p[temp-1]!=-1){
            temp=p[temp-1];
            level++;
        }
        if(ans<level){
            ans=level;
        }
    }
    cout<<ans<<endl;    
}