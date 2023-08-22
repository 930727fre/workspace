#include <stdio.h>
#include <string.h>
int main(){
    long long temp=1;
    for(int i=0;i<10;i++){
        printf("%lld\n",temp);
        temp*=36;
    }
}
`