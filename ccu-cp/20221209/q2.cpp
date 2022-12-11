#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int x,numOfDigit=1,temp;

    scanf(" %d",&x);
    temp=x;
    while(1){
        temp=temp/16;
        if(!temp){
            break;
        }
        else{
            numOfDigit++;
        }
    }
    cout<<"numOfDigit = "<<numOfDigit<<"\n";

}