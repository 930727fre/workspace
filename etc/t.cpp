#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

int fc(vector<int>& temp){
    cout<<&temp<<endl;
    cout<<temp[0]<<endl;
    temp.push_back(2);
    return 0;
}
int main(){
    for(int i=0;i<3;i++){
        cout<<i<<endl;
    }
    cout<<endl;
    for(int i=0;i<3;++i){
        cout<<i<<endl;
    }
    cout<<endl;    

}