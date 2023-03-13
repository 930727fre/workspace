#include <stdio.h>
int boss[2000],ans;
void merge(int, int);
int find(int);
int main(){
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    ans=n;
    for(int i=0;i<n;i++){
        boss[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        merge(a,b);
    }
    printf("%d\n",ans);
}

int find(int a){
    if(boss[a]==a){
        return a;
    }
    else{
        boss[a]=find(boss[a]);
        return boss[a];
    }
}
void merge(int a, int b){
    if(find(a)==find(b)){
        return;
    }
    else{
        boss[b]=find(a);
        ans--;
        return;
    }
}