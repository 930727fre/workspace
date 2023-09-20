#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int>>& v){
    int flag;

    for(int i=0;i<3;i++){
        if(v[i][0]==v[i][1]&&v[i][1]==v[i][2]){
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        if(v[0][i]==v[1][i]&&v[1][i]==v[2][i]){
            return 1;
        }
    }
    if(v[0][0]==v[1][1]&&v[2][2]==v[1][1]){
        return 1;
    }
    if(v[0][2]==v[1][1]&&v[2][0]==v[1][1]){
        return 1;
    }   
    return 0; 
}

int main(){
    vector<vector<int>> v(3, vector<int>(3,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    if(check(v)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}