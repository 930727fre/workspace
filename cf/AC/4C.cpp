#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    char str[n][33],temp[33];
    int count[n],flag,size=0;
    for(int i=0;i<n;i++){
        flag=0;
        cin>>temp;
        for(int j=0;j<size;j++){
            if(!strcmp(temp,str[j])){
                flag=1;
                cout<<temp<<count[j]<<endl;
                count[j]++;
                break;
            }
        }
        if(flag==0){
            count[size]=1;
            strcpy(str[size],temp);
            size++;
            cout<<"OK"<<endl;
        }
    }
}

/*
map
4
abacaba
acaba
abacaba
acab

*/