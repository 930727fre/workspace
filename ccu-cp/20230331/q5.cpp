#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct cake{
    double v;
    double h;
    double avg;
}Cake[100000];

int cmp(cake a, cake b){
    return a.avg<b.avg;
}
int main(){
    int n,x,ans=0,i;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>Cake[i].v>>Cake[i].h;
        Cake[i].avg=Cake[i].h/Cake[i].v;
    }
    sort(Cake, Cake+n, cmp);
    i=n-1;
    while(x&&i>=0){
        if(Cake[i].v){
            ans+=Cake[i].avg;
            Cake[i].v--;
            x--;
            // printf("%d\n",ans);
        }
        else{
            i--;
        }
    }
    cout << fixed << setprecision(7) <<ans <<endl;
}