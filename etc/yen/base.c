#include <stdio.h>

int main(){
    long long int flag, n, a, aMulti;
    n=700000000;
    a=16;
    aMulti=a;
    while(aMulti<n){
        aMulti=aMulti*a;
        printf("%lld\n",aMulti);
    }
    aMulti/=a; //aMulti=64
    while(aMulti!=1){
        if(n/aMulti>=10){
            printf("%c ",(int)(n/aMulti)+'A'-10);
        }
        else{
            printf("%lld ",n/aMulti);
        }
        n=n%aMulti;
        aMulti=aMulti/a;
    }
        if(n/aMulti>=10){
            printf("%c",(int)(n/aMulti)+'A'-10);
        }
        else{
            printf("%lld",n/aMulti);
        }    
}
