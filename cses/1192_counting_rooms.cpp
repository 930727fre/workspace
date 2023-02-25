#include <iostream>
using namespace std;
char arr[1050][1050];
int n,m,ans=0;
int travel(int, int);
int main(){
    cin>>n>>m;
    for(int i=0;i<=m+1;i++){
        arr[0][i]='#';
        arr[n+1][i]='#';
    }
    for(int i=0;i<n;i++){
            arr[i+1][0]='#';
            arr[i+1][m+1]='#';
        for(int j=0;j<m;j++){
            cin>>arr[i+1][j+1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i+1][j+1]=='.'){
                ans++;
                cout<<i<<" "<<j<<endl;
                travel(i+1,j+1);
            }
        }
    }
    cout<<ans;

}

int travel(int x, int y){
    arr[x][y]='#';
    if(arr[x+1][y]=='.'){
        travel(x+1,y);
    }
    if(arr[x][y+1]=='.'){
        travel(x,y+1);
    } 
    if(arr[x-1][y]=='.'){
        cout<<"Hi "<<x-1<<y<<endl;
        travel(x-1,y);
    }     
    return 0;        
}