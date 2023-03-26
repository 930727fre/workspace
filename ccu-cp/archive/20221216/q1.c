#include <stdio.h>
#include <stdlib.h>
/*input
5 4 1 100 44
*/
int main(){
    int s1, s2, r, k, x, p1=0, p2=0, xPrime;// limit operation, target, current score
    scanf(" %d %d %d %d %d",&s1, &s2, &r, &k, &x);
    for(int i=0;i<=r;i++){
        for(int j=0;j+i<=r;j++){
            if(((abs(x+s1*i-s2*j-k)==abs(xPrime-k))&&((x+s1*i-s2*j)<xPrime))||(abs(x+s1*i-s2*j-k)<abs(xPrime-k))||(i==0&&j==0)){
                p1=i;
                p2=j;                    
                xPrime=abs(x+s1*i-s2*j);
            }
        }
    }
    printf("%d %d %d",p1,p2,xPrime);
}