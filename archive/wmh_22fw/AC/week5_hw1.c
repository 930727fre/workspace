#include<stdio.h>

int main(){
    int x,y,z,a,b;
    while(scanf(" %d%d",&x,&y)!=EOF){
        a=x;
        b=y;
        if(b>a){
            z=a;
            a=b;
            b=z;
        }
        while(1){
            z=a%b;
            a=b;
            if(z==0){
                break;
            }
            else{
                b=z;
            }
        }
       printf("%d\n",364/((x*y)/a)+1);
    }
}