#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int n,a[1000000],b[1000000];
    double ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }    
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
    }
    // ans*=10000;
    // ans=(int)ans;
    // ans/=10000;
    // cout<<ans<<endl;
    cout << fixed << setprecision(7) <<ans << '\n';
}