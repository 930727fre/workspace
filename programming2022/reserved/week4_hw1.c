#include <stdio.h>
#include <math.h>

int main(){
    int t,x,b;
    double squareRoot;
    scanf(" %d", &t);
    for(int a=0;a<t;a++){
        scanf(" %d",&x);
        squareRoot=pow(x,0.5);
        b=2;
        while(1){
            if(x==1){
                printf("NO\n");
                break;
            }
            else if(b>squareRoot){
                printf("YES\n");
                break;
            }
            else if(x%b==0){
                printf("NO\n");
                break;
            }
            else{
                b++;
            }

        }

    }


    return 0;
}