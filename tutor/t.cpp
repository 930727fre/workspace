#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

class q{

    public:
        int height;
        int weight;
    q(void){
        height=1;
        weight=2;
        cout<<"hi\n";
    }     
};
int main(){
    q q1,q2;
    cout<<q1.height<<q1.weight;
    cout<<endl<<q2.height<<q2.weight<<endl;
}
