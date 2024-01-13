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
    vector<int> num;
    cout<<&num<<endl;
    num.push_back(1);
    fc(num);
    cout<<num[1]<<endl;
    return 0;
}