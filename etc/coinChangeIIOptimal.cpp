//Leetcode 518
#include <iostream>
#include <stdlib.h>

using namespace std;
int main(){
    int amount=5;
    int coins[]={1,2,5},size=sizeof(coins)/4;
    int* arr=(int*)malloc((amount+1)*sizeof(int));
    arr[0]=1;
    for(int i=1;i<=amount;i++){
        arr[i]=0;
    }
    for(int i=0;i<size;i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i]>=0){
                arr[j]+=arr[j-coins[i]];
            }
            //cout<<arr[j]<<" ";
        }
        //cout<<endl;
    }    
    cout<<arr[amount]<<endl;


}