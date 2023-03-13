#include <iostream>
using namespace std;
int set_sz[1000000],boss[1000000];
int find(int);
void init(int);
int union_set(int x, int y);

int main(){
    int n,m,q,x,y;
    cin>>n>>m>>q;
    init(n);

    for(int i=0;i<m;i++){
        cin>>x>>y;

        union_set(x,y);
    }

    for(int i=0;i<q;i++){
        
        cin>>x>>y;

        if(find(x)==find(y)){
            cout<<"My friends!\n";
            continue;
        }
        
        cout<<"Mirudayo\n";
    }
}

void init(int n){

    for(int i=0;i<n;i++){
        boss[i]=i;
        set_sz[i]=1;
    }
}

int find(int i){

    if(boss[i]==i)  return i;
    return boss[i]=find(boss[i]);
}


int union_set(int x, int y){

    int boss_x=find(x), boss_y=find(y);
    
    if(boss_x==boss_y)  return 0;

    if(set_sz[boss_x]<set_sz[boss_y]){

        int temp=boss_x;
        boss_x=boss_y;
        boss_y=temp;
    }

    boss[boss_y]=boss_x;
    set_sz[boss_x]+=set_sz[boss_y];

    return 1;
}