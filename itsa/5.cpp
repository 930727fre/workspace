#include <bits/stdc++.h>
using namespace std;

void invert(int(&ref)[8]){
    for(int i=0;i<8;i++){
        if(ref[i]==1){
            ref[i]=0;
        }
        else{
            ref[i]=1;
        }
    }
}
int main(){
    int input, arr[8];
    for(int i=0;i<8;i++){
        arr[i]=0;
    }
    cin>>input;
    if(input>0){
        for(int i=7;i>=0;i--){
            if(input>=pow(2,i)){
                arr[i]=1;
                input-=pow(2,i);
            }
        }
    }
    else{
        input*=-1;
        for(int i=7;i>=0;i--){
            if(input>=pow(2,i)){
                arr[i]=1;
                input-=pow(2,i);
            }
        }
        invert(arr);
        arr[0]+=1;
        for(int i=0;i<=7;i++){
            if(arr[i]==2){
                arr[i]=0;
                if(i!=7){
                    arr[i+1]++;
                }
            }
        }
    }
    for(int i=7;i>=0;i--){
        cout<<arr[i];
    }
    cout<<endl;
}