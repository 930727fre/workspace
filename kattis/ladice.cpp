#include <iostream>
#include <vector>
using namespace std;
int **arr, *drawer;
int fc(int i, int j){
    return 0;
};
int main(){

    int n,l;
    cin>>n>>l;
    arr=(int**)malloc(4*2*(n+1));
    drawer=(int*)malloc(4*(n+1));
    for(int i=1;i<=n;i++){
        cin>>arr[i][0]>>arr[i][1];
        fc(arr[i][0],arr[i][1]);
    }
}