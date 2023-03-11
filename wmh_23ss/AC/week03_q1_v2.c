#include <stdio.h>
int set_sz[1000000],boss[1000000];
int find(int);
void init(int);
int union_set(int x, int y);

int main(){
    int n,m,x,y,ans=0;
    scanf("%d %d",&n,&m);
    init(n);

    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        union_set(x,y);
    }
    for(int i=0;i<n;i++){
        if(boss[i]==i){
            ans++;
        }
    }
    printf("%d",ans);

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