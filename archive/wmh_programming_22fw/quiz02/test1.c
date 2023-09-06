#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
    unsigned a=1147497589,n;
    for(int i=4;i>=0;i--){
        n =a;
        n = n<<4*(31-i);
        n = n>>28;        
        printf("%x\n",n);
    }

}

//00 00 00 00 44 65 6c 75