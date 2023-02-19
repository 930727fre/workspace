#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int **ptr;
    ptr=(int**)malloc(1);
    ptr[0][0]=1;
    cout<<ptr[0][0];
}