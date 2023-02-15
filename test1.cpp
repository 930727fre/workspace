#include <iostream>
#include <cstdlib>
using namespace std;
int main(){

    char *ptr,*n;
    ptr=(char*)malloc(18);
    n=(char*)malloc(18);
    cin>>n;
    strcpy(ptr,n);
    cout<<sizeof(ptr)<<ptr;
}