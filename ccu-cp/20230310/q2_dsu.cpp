#include <iostream>
using namespace std;
int set_sz[1000000],boss[1000000];
int find(int);
void init(int);
int union_set(int x, int y);
int main(){
    int n;
    cin>>n;
    init(n);
}

void init(int n){
    for(int i=0;i<n;i++){
        boss[i]=i;
        set_sz[i]=1;
    }
}

int find(int i){
    if(boss[i]==i){
        return i;
    }
    else{
        return boss[i]=find(boss[i]);
    }
}

int union_set(int x, int y){
    int boss_x=find(x), boss_y=find(y);
    if(boss_x==boss_y){
        return 0;
    }
    else{
        
    }
}