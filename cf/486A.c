#include <stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);
    if(n%2!=0){
        printf("%lld",n/2-n);
    }
    else{
        printf("%lld",n/2);
    }
}