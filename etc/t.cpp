#include <vector>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string str="()", temp;
    int length=str.size();
    for(int i=0;i<=length;i++){
        temp="()";
        cout<<temp.insert(i,"()")<<endl;
    }

}