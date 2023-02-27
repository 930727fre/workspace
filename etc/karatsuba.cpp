#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
LL karatsuba(LL,LL);
int main(){
    LL x,y;
    cin>>x>>y;
    cout<<karatsuba(x,y);

}

LL karatsuba(LL x, LL y){
    if(x<10&&y<10){
        return x*y;
    }
    else{
        double half=max(log10(x),log10(y))/2;
        half=1+(int)half;
        int a=x/pow(10,half);
        int b=x-a;
        int c=y/pow(10,half);
        int d=y-c;
        return karatsuba(a,c)*pow(10,1+max(log10(x),log10(y)))+(karatsuba(a+b,c+d)-karatsuba(a,c)-karatsuba(b,d))*pow(10,half)+karatsuba(b,d);
    }
}